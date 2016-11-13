#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <GameObject.h>
#include "GameObjectFactory.h"

class HealthBar : public GameObject
{
    public:
        HealthBar();
        virtual ~HealthBar();
        void draw();
        void update();
        void clean();
        std::string gettypeID(){return "HEALTH";}
        void boom(){}
        void load(int,int,int,int,int,int,std::string);
    protected:
    private:
};

class healthCreator:public BaseCreator
{
public:
    healthCreator():BaseCreator(){}
    virtual ~healthCreator(){}
    GameObject*createGameObject()const
    {
        return new HealthBar();
    }
};
#endif // HEALTHBAR_H
