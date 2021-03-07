#include <cmath>

class Sort
{
private:
    template <class T>
    static void heapify(T *ptr, int size, int i);
    template <class T>
    static void heapifyWithRecursion(T *ptr, int size, int i);

public:
    Sort() {}
    ~Sort() {}
    template <class T>
    static bool sorted(T *ptr, int size);

    template <class T>
    static T *shell(T *ptr, int size);

    template <class T>
    static T *heapsort(T *ptr, int size);
};

template <class T>
bool Sort::sorted(T *ptr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (ptr[i] > ptr[i + 1])
            return false;
    }
    return true;
}

template <class T>
T *Sort::shell(T *ptr, int size)
{
    int step, i, j;
    T temp;

    for (step = size / 2; step > 0; step /= 2)
    {
        for (i = step; i < size; ++i)
        {
            for (j = i - step; j >= 0 && ptr[j] > ptr[j + step]; j -= step)
            {
                temp = ptr[j];
                ptr[j] = ptr[j + step];
                ptr[j + step] = temp;
            }
        }
    }
    return ptr;
}

// heapsort
template <class T>
void Sort::heapifyWithRecursion(T *ptr, int size, int i)
{
    T temp;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && ptr[i] < ptr[left])
        largest = left;

    if (right < size && ptr[largest] < ptr[right])
        largest = right;

    if (largest != i)
    {
        temp = ptr[largest];
        ptr[largest] = ptr[i];
        ptr[i] = temp;

        heapifyWithRecursion(ptr, size, largest);
    }
}

template <class T>
void Sort::heapify(T *ptr, int size, int i)
{
    T temp;
    int left, right, largest = i;
    do
    {
        left = 2 * i + 1;
        right = 2 * i + 2;

        if (left < size && ptr[i] < ptr[left])
            largest = left;

        if (right < size && ptr[largest] < ptr[right])
            largest = right;

        if (largest != i)
        {
            temp = ptr[largest];
            ptr[largest] = ptr[i];
            ptr[i] = temp;
            i = largest;
        }
        else
            return;

    } while (true);
}

template <class T>
T *Sort::heapsort(T *ptr, int size)
{
    T temp;
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(ptr, size, i);

    for (int i = size - 1; i > 0; --i)
    {
        temp = ptr[0];
        ptr[0] = ptr[i];
        ptr[i] = temp;

        heapify(ptr, i, 0);
    }
    return ptr;
}
