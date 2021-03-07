#include <iostream>
const int POINT_MIN = 0;
const int POINT_MAX = 100;

class Point
{
private:
    double x, y, z;
    double dist; // distance from (0,0,0)

public:
    Point();
    Point &operator=(const Point &p);
    Point(const Point &p);
    friend bool operator==(const Point &p1, const Point &p2);
    friend bool operator>(const Point &p1, const Point &p2);
    friend bool operator>=(const Point &p1, const Point &p2);
    friend bool operator<(const Point &p1, const Point &p2);
    friend bool operator<=(const Point &p1, const Point &p2);

    friend std::ostream &operator<<(std::ostream &out, const Point &p);
};
