#include "hammerMan.h"
#include "Camera.h"
#include "Game.h"
#include "CollosionManager.h"
#include "SoundManager.h"

hammerMan::hammerMan()
{
    moveLeft = true;
    moveRight = false;
    can_attack = true;
    attack = false;
    health = 26;
    num_frames = 4;
    //ctor
}

hammerMan::~hammerMan()
{
    //dtor
}

void hammerMan::update()
{
  //while(attack)SoundManager::Instance()->playSound("enemy",0);


  if((main_char->getpos().getX()-position.getX()<100 and main_char->getpos().getX()-position.getX()>0) and can_attack)
   {
       ///player ahead of attacker
       //flip = true;
       SoundManager::Instance()->playSound("enemy",10);
       if(moveRight == false)
       moveRight = true;
       moveLeft = false;
       attack = true;
       can_attack = false;
       num_frames = 3;
       currentRow = 1;
       width = 80;
   }

   else if((position.getX()-main_char->getpos().getX()<100 and position.getX()-main_char->getpos().getX()>0)and can_attack)
   {
       SoundManager::Instance()->playSound("enemy",10);
       if(moveLeft == false)moveLeft = true;
       moveRight = false;
       attack = true;
       can_attack = false;
       num_frames = 3;
       currentRow = 1;
       width = 80;
   }
   if(main_char->getpos().getX()-position.getX()>100)
   {
       attack = false;
       can_attack = true;
       num_frames=4;
       currentRow = 0;
       width = 60;
   }
    if(position.getX()-main_char->getpos().getX()>100)
   {
       attack = false;
       can_attack = true;
       num_frames=4;
       currentRow = 0;
       width = 60;
   }
   if(moveLeft){
        velocity.setX(-4);
        currentFrame = ((SDL_GetTicks()/(1000/8))%num_frames);
        flip = false;
    }
    if(moveRight){
        velocity.setX(4);
        currentFrame = ((SDL_GetTicks()/(1000/8))%num_frames);
        flip=true;
    }
    handleMovement(velocity);
}

void hammerMan::draw()
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

void hammerMan::clean()
{

}
void hammerMan::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
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

void hammerMan::handleMovement(vector2D velocity)
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

void hammerMan::boom()
{
    health-=2;
    if(health == 0)dead = true;
}
