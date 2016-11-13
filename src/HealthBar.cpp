#include "HealthBar.h"
#include "Game.h"

HealthBar::HealthBar()
{
    //ctor
}

HealthBar::~HealthBar()
{
    //dtor
}

void HealthBar::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
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


void HealthBar::clean()
{

}

void HealthBar::update()
{
   if(ID=="health_text")return;
    width=main_char->getHealth();
    if(width<0)dead=true;
}

void HealthBar::draw()
{
    if(ID=="health_text")
    TextureManager::Instance()->drawBack(ID,10,35,width,height,
                                         0,currentFrame,Game::Instance()->getRenderer());
    else
    TextureManager::Instance()->drawBack(ID,10,20,width,height,
                                         0,currentFrame,Game::Instance()->getRenderer());
}
