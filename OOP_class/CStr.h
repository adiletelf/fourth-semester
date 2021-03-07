#pragma once
#include <iostream>

const int MIN_LEN = 0;
const int MAX_LEN = 20;
const int MIN_ACSII = 32;
const int MAX_ACSII = 127;

class CStr
{
private:
    char *str;
    char *generate(int length); // checks condition MIN_LEN < length <= MAX_LEN

public:
    CStr(); // random length
    CStr(int length);
    CStr(char *string, int size);
    CStr(const CStr &cstr);
    ~CStr();

    CStr &operator=(char string[]);
    CStr &operator=(const CStr &cstr);
    bool operator>(const CStr &cstr);
    bool operator<(const CStr &cstr);
    bool operator==(const CStr &cstr);

    int getLength() const;

    friend std::ostream &operator<<(std::ostream &out, const CStr &cstr);
};
