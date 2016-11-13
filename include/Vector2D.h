#ifndef VECTOR2D_H
#define VECTOR2D_H
#include<cmath>
/* This class is the exact implementation of a real time vector and supports all vector operation and by vector I mean the
   vectors in physics sense and not in C++ sense , the objects of this class are used in object classes as parameters as their
   velocity, acceleration and position etc. */

class vector2D
{
    public:
        vector2D(float,float);
        vector2D(){}
        virtual ~vector2D();
        void setX(float);
        void setY(float);
        float getX();
        float getY();
        float length();
        vector2D operator+(const vector2D&v2)const;
        friend vector2D& operator+=(vector2D&v1,const vector2D&v2);
        vector2D operator*(float scalar);
        vector2D operator*=(float scalar);
        vector2D operator-(const vector2D&v2)const;
        friend vector2D& operator-=(vector2D&v1,const vector2D&v2);
        vector2D operator/(float scalar);
        void normalize();
    protected:
    private:
        float x;
        float y;

};

#endif // VECTOR2D_H
