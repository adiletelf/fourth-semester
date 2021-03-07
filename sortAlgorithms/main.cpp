#include "Point.h"
#include "Sort.h"
#include <iostream>
#include <chrono>
#include <random>

template <class T>
void check(T *arr, int n, int shell = 0) // if shell == 1  => heapsort
{
    T *ptr = new T[n];
    for (int i = 0; i < n; ++i)
        ptr[i] = arr[i];

    auto start = std::chrono::high_resolution_clock::now();
    if (shell)
        Sort::shell(ptr, n);
    else
        Sort::heapsort(ptr, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    std::cout << "Original array sorted: " << Sort::sorted(arr, n) << '\n';
    if (shell)
        std::cout << "Using shell algorithm\n";
    else
        std::cout << "Using heapsort algorithm\n";
    std::cout << "Sorted: " << Sort::sorted(ptr, n) << '\n';
    std::cout << "Seconds elapsed: " << elapsed << "(ms)\n\n";

    delete[] ptr;
}

int *createAscendingArr(int size)
{
    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = i;
    }
    return arr;
}

int *createDescendingArr(int size)
{
    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = size - i;
    }
    return arr;
}

int *createRandomArr(int size)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt(seed);
    std::uniform_int_distribution<std::mt19937::result_type> distribution(POINT_MIN, POINT_MAX);
    int *arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = distribution(mt);
    }
    return arr;
}

template <class T>
void sort(T *arr, int n)
{
    check(arr, n, 0);
    check(arr, n, 1);
}

int main()
{
    std::cout << std::boolalpha;
    int n = 1000000;

    int *arr1 = createAscendingArr(n);
    std::cout << "Ascending array:\n";
    sort(arr1, n);

    int *arr2 = createDescendingArr(n);
    std::cout << "\nDescending array:\n";
    sort(arr2, n);

    int *arr3 = createRandomArr(n);
    std::cout << "\nRandom array:\n";
    sort(arr3, n);

    Point *arr4 = new Point[n];
    std::cout << "\nPoints array:\n";
    sort(arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
}

// int main()
// {
//     std::cout << std::boolalpha;

//     int size = 100000;
//     Point *ptr = new Point[size];
//     std::cout << Sort::sorted(ptr, size) << '\n';
//     check(ptr, size, 0);
//     check(ptr, size, 1);

//     delete[] ptr;
//     return 0;
// }
