#include "Elephant.h"
#include "Camera.h"
#include "Game.h"
#include "CollosionManager.h"
#include "SoundManager.h"
Elephant::Elephant()
{
    wait=20;
    //ctor
}

Elephant::~Elephant()
{
    //dtor
}

void Elephant::draw()
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

void Elephant::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
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
    moveRight = true;
    moveLeft = false;
    if(_ID == string("elephant"))num_frames = 4;
    else num_frames = 6;
}

void Elephant::handleInput()
{

    if(position.getX()-main_char->getpos().getX()<300)
    {
        //if(!SoundManager::Instance()->load("assets/3.wav","ele",SOUND_SFX))std::cout<<"ERROR\n";

        Mix_Volume(-1,MIX_MAX_VOLUME/40);
        if(ID==std::string("elephant"))
        SoundManager::Instance()->playSound("ele",0);
        else
        SoundManager::Instance()->playSound("roar",0);
        wait--;
        if(wait == 0){
        flip = false;
        moveRight = false;
        moveLeft = true;
        }
    }
    if(main_char->getpos().getX()-position.getX()>700)
    {
        SoundManager::Instance()->stop("ele");
        SoundManager::Instance()->stop("roar");
        dead = true;
       Mix_Volume(-1,MIX_MAX_VOLUME);

    }
}

void Elephant::update()
{

    handleInput();
    if(moveLeft)velocity.setX(-15);
    if(moveRight)velocity.setX(0);
    currentFrame = ((SDL_GetTicks()/(1000/8))%num_frames);
    handleMovement(velocity);
}

void Elephant::handleMovement(vector2D velocity)
{
    vector2D newPos = position;
    newPos.setX(position.getX() + velocity.getX());
    if(!CollosionManager::Instance()->checkPlayerTileCollosion(newPos,width,height)){
            position = newPos;

    }
    else {
            velocity.setX(0);
            if(!moveLeft){moveLeft = true;moveRight = false;}
            else if(!moveRight){moveRight = true;moveLeft =false;}
            if(ID=="elephant");

    }

}

void Elephant::boom()

{
    moveLeft = false;
    moveRight = false;

    while(main_char->getHealth()!=0)main_char->boom();

}

void Elephant::clean()
{

}
