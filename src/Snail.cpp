#include "Snail.h"
#include "CollosionManager.h"
#include "Camera.h"

Snail::Snail()
{
    moveRight = true;
    moveLeft = false;
    dyingCounter = 0;
    //ctor
}

Snail::~Snail()
{
    //dtor
}

void Snail::update()
{
    if(moveLeft){
        velocity.setX(-4);
        currentFrame = ((SDL_GetTicks()/(1000/8))%4);
        flip = false;
    }
    if(moveRight){
        velocity.setX(4);
        currentFrame = ((SDL_GetTicks()/(1000/8))%4);
        flip=true;
    }
    handleMovement(velocity);
}


void Snail::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
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

void Snail::handleMovement(vector2D velocity)
{
    vector2D newPos = position;
    newPos.setX(position.getX() + velocity.getX());
    if(!CollosionManager::Instance()->checkPlayerTileCollosion(newPos,width,height))position = newPos;
    else {
            velocity.setX(0);
            if(!moveLeft){moveLeft = true;moveRight = false;}
            else if(!moveRight){moveRight = true;moveLeft =false;}
    }

}

void Snail::draw()
{

     if(flip == true)
    {
        TextureManager::Instance()->drawFrame(ID,int(position.getX()-Camera::Instance()->getPosition().getX()),
                                              int(position.getY()),
                                              width,height,currentRow,currentFrame,Game::Instance()->getRenderer(),
                                              SDL_FLIP_HORIZONTAL);
    }
     else
    {
        TextureManager::Instance()->drawFrame(ID,int(position.getX()-Camera::Instance()->getPosition().getX())
                                              ,int(position.getY()),
                                              width,height,currentRow,currentFrame,Game::Instance()->getRenderer());
    }
}
void Snail::clean()
{

}

void Snail::boom()
{
    currentRow = 1;
    currentFrame = ((SDL_GetTicks()/(1000/8))%4);
    moveLeft = moveRight = false;
    if(dyingCounter==1)dead = true;
    dyingCounter++;
}
