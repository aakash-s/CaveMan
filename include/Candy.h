#ifndef CANDY_H
#define CANDY_H

#include <GameObject.h>
#include "GameObjectFactory.h"

class Candy : public GameObject
{
    public:
        Candy();
        virtual ~Candy();
        void update(){}
        std::string gettypeID(){return "PICKUP";}
        void draw();
        void boom(){dead = true;}
        void load(int,int,int,int,int,int,std::string);
        void clean(){}
    protected:
    private:
};
class pickupCreator:public BaseCreator
{
public:
    pickupCreator():BaseCreator(){}
    virtual ~pickupCreator(){}
    GameObject*createGameObject()const
    {
        return new Candy();
    }
};
#endif // CANDY_H
