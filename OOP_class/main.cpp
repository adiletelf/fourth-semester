#include "CStr.h"
#include "CStrArray.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(nullptr));
    std::cout << std::boolalpha;
    // CStr s1, s2;
    // std::cout << "s1: " << s1 << '\n';
    // std::cout << "s2: " << s2 << '\n';
    // std::cout << "s1 > s2 : " << (s1 > s2) << '\n';
    // std::cout << "s1 < s2 : " << (s1 < s2) << '\n';
    // std::cout << "s1 == s2 : " << (s1 == s2) << '\n';

    int length = 20;
    int size = 10;
    // std::cin >> size >> length;

    std::cout << "Length of strings: " << length << '\n';
    std::cout << "Size of CStrArray array: " << size << "\n\n";

    CStrArray carr(size);
    std::cout << "Array sorted: " << carr.sortedByContent() << "\n\n";
    carr.sortByContent();
    std::cout << carr;
    std::cout << "Sorted by content: " << carr.sortedByContent() << "\n\n";

    CStrArray carr2(size);
    std::cout << "Array sorted: " << carr2.sortedByLen() << "\n\n";
    carr2.sortByLen();
    std::cout << carr2;
    std::cout << "Sorted by length: " << carr2.sortedByLen() << "\n\n";

    return 0;
}
