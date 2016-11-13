#include "Collosion.h"
Collosion*Collosion::_instance = 0;

Collosion::Collosion()
{
    //ctor
}

Collosion::~Collosion()
{
    //dtor
}

Collosion*Collosion::Instance()
{
    if(_instance == 0)_instance = new Collosion();
    return _instance;
}

bool Collosion::collided(SDL_Rect*A,SDL_Rect*B)
{
    int aHBuf = A->h/4;
    int aWBuf = A->w/4;

    int bHBuf = B->h/4;
    int bWBuf = B->w/4;

    /// if the bottom of A is less than the top of B - no collision
    if((A->y + A->h) - aHBuf <= B->y + bHBuf)  { return false; }

    /// if the top of A is more than the bottom of B = no collision
    if(A->y + aHBuf >= (B->y + B->h) - bHBuf)  { return false; }

    /// if the right of A is less than the left of B - no collision
    if((A->x + A->w) - aWBuf <= B->x +  bWBuf) { return false; }

    /// if the left of A is more than the right of B - no collision
    if(A->x + aWBuf >= (B->x + B->w) - bWBuf)  { return false; }

    // otherwise there has been a collision
    return true;
}
