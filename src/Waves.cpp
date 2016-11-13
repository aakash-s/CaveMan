#include "Waves.h"
#include "Game.h"
#include "Camera.h"

Waves::Waves()
{
    //ctor
}

Waves::~Waves()
{
    //dtor
}

void Waves::update()
{
    currentFrame = (currentFrame+10)%490;
}

void Waves::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
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
    flip = true;
    dead = false;
}

void Waves::draw()
{
    TextureManager::Instance()->drawBack(ID,int(position.getX()-Camera::Instance()->getPosition().getX())
                                         ,int(position.getY()),width,height,
                                         0,currentFrame,Game::Instance()->getRenderer());

}
