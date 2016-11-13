#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "vector2D.h"
#include "TextureManager.h"
#include "SoundManager.h"



class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();
        virtual void update();
        virtual void draw();
        virtual void clean() = 0;
        virtual std::string gettypeID()=0;
        virtual void load(int xpos,int ypos,int height,int width,int currentRow,int currentFrame,std::string ID) = 0;

        int getHeight();
        int getWidth();
        vector2D getpos();
        vector2D getvelocity();
        vector2D getacceleration();
        bool checkCollideTile(vector2D newPos);
        std::string getID();
        virtual void boom() = 0;                 /// for collosion
        bool isDead(){return dead;}
        int getRow(){return currentRow;}
        int getFrame(){return currentFrame;}
        void setFrame(int a){currentFrame = a;}
        void setHealth(int a){health = a;}
        void setVelocity(vector2D a){velocity.setX(a.getX());}

        void sethero(GameObject*a)
        {
            main_char=a;
        }
        int getHealth(){return health;}
    protected:
        vector2D position;
        vector2D velocity;
        vector2D acceleration;
        int width;
        int height;
        int currentFrame;
        int currentRow;
        std::string ID;
        bool flip;
        bool dead;
        GameObject*main_char;
        int health;
    private:


};

#endif // GAMEOBJECT_H
