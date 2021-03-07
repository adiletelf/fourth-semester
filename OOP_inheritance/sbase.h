#include <iostream>
#include <map>
#include <string>
#include <fstream>

const int DEFAULT_COUNT = 1; // default value for pair<num: freq> in Freq.freq

class SBase
{
public:
    virtual int Get() = 0;
};

class SKbrd : public SBase
{
public:
    int Get();
};

class SQueue : public SBase
{
private:
    int *arr;
    int size;
    int index;

public:
    SQueue() : arr(nullptr), size(0), index(0) {}
    SQueue(int *ptr, int size_);

    int Get();
};

class SFile : public SBase
{
private:
    std::string path;
    std::ifstream in;

public:
    SFile(std::string fpath);
    ~SFile() { in.close(); };
    int Get();
};

class Freq
{
protected:
    std::map<int, int> freq;

public:
    Freq() {}
    Freq(SBase &sbase) { Calc(sbase); };
    ~Freq() {}

    void Calc(SBase &sbase);

    friend std::ostream &operator<<(std::ostream &out, Freq &f);
};

class Diap : public Freq
{
protected:
    int min;
    int max;
    int sum;

public:
    Diap();
    Diap(SBase &sbase) { Calc(sbase); }
    ~Diap() {}

    void Calc(SBase &sbase);

    friend std::ostream &operator<<(std::ostream &out, Diap &d);
};
