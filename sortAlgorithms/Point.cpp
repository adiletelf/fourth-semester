#include "Point.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
// #include <random>
// #include <chrono>
// Point::Point()
// {
//     auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
//     std::mt19937 mt(seed);
//     std::uniform_int_distribution<std::mt19937::result_type> distribution(POINT_MIN, POINT_MAX);

//     x = distribution(mt);
//     y = distribution(mt);
//     z = distribution(mt);
//     dist = sqrt(x * x + y * y + z * z);
// }

Point::Point()
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(nullptr));
        seeded = true;
    }

    x = rand() % POINT_MAX;
    y = rand() % POINT_MAX;
    z = rand() % POINT_MAX;
    dist = sqrt(x * x + y * y + z * z);
}

Point &Point::operator=(const Point &p)
{
    x = p.x;
    y = p.y;
    z = p.z;
    dist = p.dist;
    return *this;
}

Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    z = p.z;
    dist = p.dist;
}

bool operator==(const Point &p1, const Point &p2)
{
    if (p1.x == p2.x && p1.y == p2.y && p1.z == p2.z)
        return true;
    return false;
}

bool operator>(const Point &p1, const Point &p2)
{
    if (p1.dist > p2.dist)
        return true;
    return false;
}

bool operator>=(const Point &p1, const Point &p2)
{
    if (p1.dist >= p2.dist)
        return true;
    return false;
}

bool operator<(const Point &p1, const Point &p2)
{
    if (p1.dist < p2.dist)
        return true;
    return false;
}

bool operator<=(const Point &p1, const Point &p2)
{
    if (p1.dist <= p2.dist)
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
    out << '(' << p.x << ',' << p.y << ',' << p.z << ") distance from (0,0,0): " << p.dist;
    return out;
}