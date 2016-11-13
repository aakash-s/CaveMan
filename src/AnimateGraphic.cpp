#include "AnimateGraphic.h"

AnimateGraphic::AnimateGraphic()
{
    //ctor
}

AnimateGraphic::~AnimateGraphic()
{
    //dtor
}

void AnimateGraphic::update()
{
       currentFrame = ((SDL_GetTicks()/(1000/2))%2);
}

void AnimateGraphic::draw()
{
    GameObject::draw();
}

void AnimateGraphic::clean()
{

}
void AnimateGraphic::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
{
    velocity.setX(0);velocity.setY(0);
    acceleration.setX(0);acceleration.setY(0);
    position.setX(xpos);
    position.setY(ypos);
    width = _width;
    height = _height;
    ID = _ID;
    currentRow = _cR;
    currentFrame = _cF;
    flip = 0;
    dead = false;
}
