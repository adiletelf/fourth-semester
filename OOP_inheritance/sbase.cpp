#include "sbase.h"

// SKbrd
int SKbrd::Get()
{
    int num;
    while (true)
    {
        std::cout << "Enter a number: ";
        std::cin >> num;

        if (std::cin.fail())
        {
            std::cin.clear();             // возвращает cin в "обычный" режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return num;
        }
    }
}

// SQueue
SQueue::SQueue(int *ptr, int size_)
{
    if (size_ < 0)
    {
        size_ = 0;
        index = 0;
        arr = nullptr;
        return;
    }

    index = 0;
    size = size_;
    arr = ptr;
}

int SQueue::Get()
{
    if (index < size)
        return arr[index++];
    else
        return -1;
}

// SFile
SFile::SFile(std::string fpath) : in(fpath, std::ios_base::in), path("")
{
    // SFile.in is initialized, but is it open?
    if (in.is_open())
    {
        path = fpath;
    }
    else
    {
        std::cout << "Could not open file: " << fpath << '\n';
        in.close();
    }
}

int SFile::Get()
{
    if (in.eof() || !in.is_open())
        return -1;
    else
    {
        int num;
        in >> num;
        return num;
    }
}

// Freq
void Freq::Calc(SBase &sbase)
{
    freq.clear();
    std::map<int, int>::iterator itr;

    std::cout << "Enter a negative number to exit.\n";
    int num = sbase.Get();
    while (num >= 0)
    {
        itr = freq.find(num);
        if (itr != freq.end())
            itr->second += 1;
        else
            freq.insert(std::pair<int, int>(num, DEFAULT_COUNT));

        num = sbase.Get();
    }
}

std::ostream &operator<<(std::ostream &out, Freq &f)
{
    std::map<int, int>::iterator itr;
    for (itr = f.freq.begin(); itr != f.freq.end(); ++itr)
    {
        out << "Num: " << itr->first << ' '
            << "Count: " << itr->second << '\n';
    }
    return out;
}

// Diap
Diap::Diap()
{
    min = (unsigned int)(~0) >> 1; // max value for int
    max = 0;
    sum = 0;
}

void Diap::Calc(SBase &sbase)
{
    min = (unsigned int)(~0) >> 1; // max value for int
    max = 0;
    sum = 0;

    freq.clear();
    std::map<int, int>::iterator itr;

    int num = sbase.Get();
    while (num >= 0)
    {
        itr = freq.find(num);
        if (itr != freq.end())
            itr->second += 1;
        else
            freq.insert(std::pair<int, int>(num, DEFAULT_COUNT));

        if (num < min)
            min = num;
        if (num > max)
            max = num;

        sum += num;
        num = sbase.Get();
    }
}

std::ostream &operator<<(std::ostream &out, Diap &d)
{
    std::map<int, int>::iterator itr;
    for (itr = d.freq.begin(); itr != d.freq.end(); ++itr)
    {
        out << "Num: " << itr->first << ' '
            << "Count: " << itr->second << '\n';
    }
    out << "Min: " << d.min << " | Max: " << d.max << " | Sum: " << d.sum << '\n';

    return out;
}
