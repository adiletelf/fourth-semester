#pragma once
#include "CStr.h"
#include <iostream>

const int MAX_CSTRARRAY_SIZE = 50;

class CStrArray
{
private:
    CStr *arr;
    int size;

public:
    CStrArray(int size_); // size === capacity
    ~CStrArray();
    CStr &operator[](int index);

    int getSize();

    bool sortedByLen();
    void sortByLen();

    bool sortedByContent();
    void sortByContent();

    friend std::ostream &operator<<(std::ostream &out, const CStrArray &carr);
};
