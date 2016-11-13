#ifndef HAMMERMAN_H
#define HAMMERMAN_H

#include <GameObject.h>
#include "GameObjectFactory.h"


class hammerMan : public GameObject
{
    public:
        hammerMan();
        virtual ~hammerMan();
        void update();
        void load(int,int,int,int,int,int,std::string);
        void draw();
        void clean();
        std::string gettypeID(){return "ENEMY";}
        void handleMovement(vector2D);
        void boom();
    protected:
    private:
        bool moveLeft;
        bool moveRight;
        bool can_attack;
        bool attack;
        int health;
        int num_frames;
};

class hammerManCreator:public BaseCreator
{
public:
    hammerManCreator():BaseCreator(){}
    virtual ~hammerManCreator(){}
    GameObject*createGameObject()const
    {
        return new hammerMan();
    }
};

#endif // HAMMERMAN_H
