#include "Turtle.h"
#include "Game.h"
#include "Camera.h"
#include "CollosionManager.h"

Turtle::Turtle()
{
    moveRight = true;
    moveLeft = false;
    //ctor
}

Turtle::~Turtle()
{
    //dtor
}
void Turtle::draw()
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


void Turtle::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
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
}
void Turtle::handleMovement(vector2D velcoity)
{

    vector2D newPos = position;
    newPos.setX(position.getX() + velocity.getX());
    if(!CollosionManager::Instance()->checkPlayerTileCollosion(newPos,width,height))position = newPos;
    else {
            if(!moveLeft){moveLeft = true;moveRight = false;}
            else if(!moveRight){moveRight = true;moveLeft =false;}
    }
}


void Turtle::update()
{
    if(moveRight == true){
            velocity.setX(3);
             currentFrame = ((SDL_GetTicks()/(1000/8))%3);
             flip=true;
             }
    if(moveLeft == true){
            velocity.setX(-3);
             currentFrame = ((SDL_GetTicks()/(1000/8))%3);
             flip=false;
             }
    handleMovement(velocity);
}

