#include "CStr.h"
#include <cstdlib>
#include <cstring>

char *CStr::generate(int length)
{
    // MIN_LEN, MAX_LEN - длина строки
    // MIN_ASCII, MAX_ASCII - возможные значения символов
    if (length < MIN_LEN || length > MAX_LEN)
        length = MAX_LEN;

    str = new char[length + 1];
    for (int i = 0; i < length; ++i)
    {
        str[i] = (char)(rand() % MAX_ACSII + MIN_ACSII);
    }
    str[length] = '\0';

    return str;
}

CStr::CStr()
{
    int length = rand() % MAX_LEN + MIN_LEN;
    str = generate(length);
}

CStr::CStr(int length)
{
    str = generate(length);
}

CStr::CStr(char *string, int size)
{
    // if (size < MIN_LEN || size > MAX_LEN)
    if (size < 0)
        return;

    str = new char[size + 1];
    for (int i = 0; i < size; ++i)
        str[i] = string[i];
    str[size] = '\0';
}

CStr::CStr(const CStr &cstr)
{
    int length = cstr.getLength();
    str = new char[length + 1];
    for (int i = 0; i < length; ++i)
        str[i] = cstr.str[i];

    str[length] = '\0';
}

CStr::~CStr()
{
    delete[] str;
    str = nullptr;
}

int CStr::getLength() const
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        length += 1;

    return length;
}

CStr &CStr::operator=(char string[])
{
    int length = sizeof(&string) / sizeof(string[0]);
    delete[] str;
    str = new char[length + 1];
    for (int i = 0; i < length; ++i)
        str[i] = string[i];
    str[length] = '\0';

    return *this;
}

CStr &CStr::operator=(const CStr &cstr)
{
    if (this == &cstr)
        return *this;

    delete[] str;
    int length = cstr.getLength();
    str = new char[length + 1];
    for (int i = 0; i < length; ++i)
        str[i] = cstr.str[i];
    str[length] = '\0';

    return *this;
}

bool CStr::operator>(const CStr &cstr)
{
    return strcmp(str, cstr.str) > 0;
}

bool CStr::operator<(const CStr &cstr)
{
    return strcmp(str, cstr.str) < 0;
}

bool CStr::operator==(const CStr &cstr)
{
    return strcmp(str, cstr.str) == 0;
}

std::ostream &operator<<(std::ostream &out, const CStr &cstr)
{
    out << cstr.str;
    return out;
}
