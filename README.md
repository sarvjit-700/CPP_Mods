# CPP_Mods
my vect2.cpp
#include "vect2.hpp"
#include <cmath>

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int num1, int num2) : x(num1), y(num2) {}

vect2::vect2(const vect2 &source)
{
    *this = source;
}

vect2 &vect2::operator=(const vect2& source)
{
    if (this != &source)
    {
        this->x = source.x;
        this->y = source.y;
    }
    return *this;
}

vect2::~vect2() {}

int vect2::getX() const
{
    return (this->x);
}

int vect2::getY() const
{
    return (this->y);
}

int vect2::operator[](int index) const
{
    if (index == 0)
        return (this->x);
    return (this->y);
}

int &vect2::operator[](int index) // NON-COST
{
    if (index == 0)
        return (this->x);
    return (this->y);
}

vect2 vect2::operator-() const
{
    return vect2(this->x * -1, this->y * -1);
}

vect2 vect2::operator*(int num) const
{
    return vect2(this->x * num, this->y * num);
}

vect2 &vect2::operator*=(int num)
{
    this->x *= num;
    this->y *= num;
    return (*this);
}

vect2 &vect2::operator+=(const vect2& obj)
{
    this->x += obj.x;
    this->y += obj.y;
    return (*this);
}

vect2 &vect2::operator-=(const vect2& obj)
{
    this->x -= obj.x;
    this->y -= obj.y;
    return (*this);
}

vect2 &vect2::operator*=(const vect2& obj)
{
    this->x *= obj.x;
    this->y *= obj.y;
    return (*this);
}

vect2 vect2::operator+(const vect2& obj) const
{
    return vect2(this->x + obj.x, this->y + obj.y);
}

vect2 vect2::operator-(const vect2& obj) const
{
    return vect2(this->x - obj.x, this->y - obj.y);
}

vect2 vect2::operator*(const vect2& obj) const
{
    return vect2(this->x * obj.x, this->y * obj.y);
}

vect2 &vect2::operator++()
{
    this->x++;
    this->y++;
    return (*this);
}

vect2 vect2::operator++(int)
{
    vect2 tmp(*this);
    this->x++;
    this->y++;
    return (tmp);
}

vect2 &vect2::operator--()
{
    this->x--;
    this->y--;
    return (*this);
}
vect2 vect2::operator--(int)
{
    vect2 tmp(*this);
    this->x--;
    this->y--;
    return (tmp);
}

bool vect2::operator==(const vect2& obj) const
{
    return (this->x == obj.x && this->y == obj.y);
}

bool vect2::operator!=(const vect2& obj) const
{
    return !(*this == obj);
}

        
std::ostream& operator<<(std::ostream& os,const vect2& obj)
{
    os << "(" << obj.getX() << ", " << obj.getY() << ")";
    return os;
}

vect2 operator*(int num, const vect2& obj)
{
    return (obj * num);
}
