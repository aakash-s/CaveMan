#include "Back.h"
#include "InputHandler.h"
#include "CollosionManager.h"
Back::Back()
{

    //ctor
}

Back::~Back()
{
    //dtor
}

void Back::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
{
    velocity.setX(50);velocity.setY(0);
    acceleration.setX(0);acceleration.setY(0);
    position.setX(50);
    position.setY(ypos);
    width = _width;
    height = _height;
    ID = _ID;
    currentRow = _cR;
    currentFrame = _cF;
    flip = 0;
    dead = false;
}

void Back::draw()
{
    TextureManager::Instance()->drawBack(ID,0,0,width,height,
                                         0,currentFrame,Game::Instance()->getRenderer());
}

void Back::update()
{
   currentFrame = (int(main_char->getpos().getX()-49))%799;

}

void Back::clean()
{

}

