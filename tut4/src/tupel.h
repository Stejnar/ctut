#if !defined(TUPEL)
#define TUPEL

#include <math.h>
#include <iostream>

class Tupel
{
  public:
    float x;
    float y;

    Tupel(){};
    Tupel(float _x, float _y);

    friend Tupel operator+(Tupel lhs, const Tupel rhs)
    {
        return Tupel(lhs.x + rhs.x, lhs.y + rhs.y);
    };

    friend float operator*(Tupel lhs, const Tupel rhs)
    {
        return sqrt(float(lhs.x * rhs.x + lhs.y * rhs.y));
    };

    friend Tupel operator*(Tupel lhs, const float rhs)
    {
        return Tupel((float)lhs.x * rhs, (float)lhs.y * rhs);
    };

    friend Tupel operator*(Tupel lhs, const int rhs)
    {
        return Tupel((float)lhs.x * rhs, (float)lhs.y * rhs);
    };

    friend bool operator==(Tupel lhs, const Tupel rhs)
    {
        return round(lhs.x) == round(rhs.x) && round(lhs.y) == round(rhs.y);
    };
};

Tupel::Tupel(float _x, float _y)
{
    x = _x;
    y = _y;
};

std::ostream &operator<<(std::ostream &os, const Tupel &tupel)
{
    os << '(' << tupel.x << '|' << tupel.y << ')';
    return os;
};

#endif // TUPEL