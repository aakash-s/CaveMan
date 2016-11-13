#ifndef CAMERA_H
#define CAMERA_H
#include"Vector2D.h"
#include"Game.h"

class Camera
{
    public:
        Camera();
        virtual ~Camera();
        static Camera*Instance();
        void setTarget(vector2D*t)
        {
            target = t;
        }
        void setPosition(vector2D p)
        {
            position = p;
        }
        vector2D getPosition();
        void update(vector2D velocity);
    protected:
    private:
        static Camera*_instance;
        vector2D*target;
        vector2D position;
};

#endif // CAMERA_H
