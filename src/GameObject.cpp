#include "GameObject.h"
#include "Game.h"


GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    //dtor
}

void GameObject::update()
{
    position += velocity;
}
int GameObject::getHeight()
{
    return height;
}
int GameObject::getWidth()
{
    return width;
}
vector2D GameObject::getpos()
{
    return position;
}
vector2D GameObject::getvelocity()
{
    return velocity;
}

vector2D GameObject::getacceleration()
{
    return acceleration;
}

void GameObject::draw()
{

    if( flip == 0) /// Flip is not passed , no need to flip
    TextureManager::Instance()->drawFrame(ID,int(position.getX()),int(position.getY()),width,height,currentRow,currentFrame,
                                     Game::Instance()->getRenderer());
    else if(flip == true){
      TextureManager::Instance()->drawFrame(ID,int(position.getX()),int(position.getY()),width,height,currentRow,currentFrame,
                                     Game::Instance()->getRenderer(),SDL_FLIP_HORIZONTAL);
    }
}


std::string GameObject::getID()
{
    return ID;
}
