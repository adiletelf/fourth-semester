#include "CStrArray.h"

CStrArray::CStrArray(int size_)
{
    arr = new CStr[size_];
    size = size_;
}

CStrArray::~CStrArray()
{
    delete[] arr;
    arr = nullptr;
}

CStr &CStrArray::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        std::cerr << "Incorrect index\n";
        index = 0;
    }
    return arr[index];
}

int CStrArray::getSize()
{
    return size;
}

bool CStrArray::sortedByLen()
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i].getLength() > arr[i + 1].getLength())
            return false;
    }
    return true;
}

void CStrArray::sortByLen()
{
    int step, i, j;
    CStr temp;

    for (step = size / 2; step > 0; step /= 2)
    {
        for (i = step; i < size; ++i)
        {
            for (j = i - step; j >= 0 && arr[j].getLength() > arr[j + step].getLength(); j -= step)
            {
                temp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = temp;
            }
        }
    }
}

bool CStrArray::sortedByContent()
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

void CStrArray::sortByContent()
{
    int step, i, j;
    CStr temp;

    for (step = size / 2; step > 0; step /= 2)
    {
        for (i = step; i < size; ++i)
        {
            for (j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
            {
                temp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = temp;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &out, const CStrArray &carr)
{
    if (carr.size > MAX_CSTRARRAY_SIZE)
        return out;
    for (int i = 0; i < carr.size; ++i)
    {
        out << carr.arr[i] << '\n';
    }
    return out;
}
