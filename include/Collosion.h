#ifndef COLLOSION_H
#define COLLOSION_H
#include<SDL.h>

class Collosion
{
    public:
        Collosion();
        virtual ~Collosion();
        static Collosion*Instance();
        bool collided(SDL_Rect*A,SDL_Rect*B);
    protected:
    private:
        static Collosion*_instance;
};

#endif // COLLOSION_H
