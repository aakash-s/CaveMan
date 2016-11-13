#include "Camera.h"

Camera*Camera::_instance = 0;

Camera::Camera():target(0)
{
    position.setX(0);
    position.setY(0);
    //ctor
}

Camera::~Camera()
{
    //dtor
}

Camera*Camera::Instance()
{
    if(_instance == 0)_instance = new Camera();
    return _instance;
}

vector2D Camera::getPosition()
{
    if(target != 0)
    {
        vector2D pos(target->getX() - Game::Instance()->getGameWidth()/2,0);
        if(pos.getX()<0)pos.setX(0);
        return pos;

    }
    return position;
}

void Camera::update(vector2D velocity)
{
     position+=velocity;
     if(position.getX()<0)position.setX(0);
}
