#ifndef PLAYER_H
#define PLAYER_H

#include <GameObject.h>

#include "GameObjectFactory.h"

class Player : public GameObject
{
    public:
        Player();
        virtual ~Player();
        void update();
        void draw();
        void clean();
        void load(int,int,int,int,int,int,std::string);
        void handleMovement(vector2D);
        void handleInput();
        std::string gettypeID(){return "HERO";}
        void boom();
    protected:
    private:
        vector2D lastsafepos;
        bool jump_pressed;
        bool jumping;
        bool can_jump;
        bool moveLeft;
        bool moveRight;
        int jumpheight;
        int num_frames;
        bool attack;
        bool can_attack;
        bool run;

};


class playerCreator:public BaseCreator
{
public:
    playerCreator():BaseCreator(){}
    virtual ~playerCreator(){}
    GameObject*createGameObject()const
    {
        return new Player();
    }
};
#endif // PLAYER_H
