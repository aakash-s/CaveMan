#include "vector2D.h"

vector2D::vector2D(float _x,float _y)
{
    x = _x;
    y = _y;
    //ctor
}

vector2D::~vector2D()
{
    //dtor
}

void vector2D::setX(float _x)
{
    x = _x;
}

void vector2D::setY(float _y)
{
    y = _y;
}

float vector2D::getX()
{
    return x;
}

float vector2D::getY()
{
    return y;
}

float vector2D::length()
{
    return sqrt(x*x + y*y);
}

vector2D vector2D::operator+(const vector2D&v2)const
{
    return vector2D(x+v2.x,y+v2.y);
}

vector2D& operator+=(vector2D&v1,const vector2D&v2)
{
    v1.x = v1.x + v2.x;
    v1.y = v1.y + v2.y;
    return v1;
}

vector2D vector2D::operator*(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

vector2D vector2D::operator-(const vector2D&v2)const
{
    return vector2D(x-v2.x,y-v2.y);
}

vector2D& operator-=(vector2D&v1,const vector2D&v2)
{
    v1.x = v1.x - v2.x;
    v1.y = v1.y - v2.y;
    return v1;
}

vector2D vector2D::operator/(float scalar)
{
    x /= scalar;
    y /= scalar;
    return *this;
}

vector2D vector2D::operator*=(float scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

void vector2D::normalize()
{
    float l = length();
    if(l>0){
        (*this) *= 1/l;
    }
}

