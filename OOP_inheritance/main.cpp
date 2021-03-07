#include "sbase.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

int testSKbrd()
{
    SKbrd skey;
    Diap freq(skey);

    std::cout << freq;
    return 0;
}

int testSQueue()
{
    srand(time(nullptr));

    int n = 10;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % n;

    SQueue squeue(arr, n);
    Diap diap(squeue);
    std::cout << diap;

    delete[] arr;
    return 0;
}

int testSFile()
{
    std::string fpath{"data.txt"};
    SFile sfile(fpath);

    Diap diap(sfile);
    std::cout << diap;

    return 0;
}

int main()
{
    std::cout << "Testing SKbrd\n";
    testSKbrd();
    std::cout << '\n';

    std::cout << "Testing SQueue\n";
    testSQueue();
    std::cout << '\n';

    std::cout << "Testing SFile\n";
    testSFile();
    std::cout << '\n';

    return 0;
}
