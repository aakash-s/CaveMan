#ifndef WAVES_H
#define WAVES_H

#include <GameObject.h>
#include "GameObjectFactory.h"

class Waves : public GameObject
{
    public:
        Waves();
        virtual ~Waves();
        void update();
        void clean(){}
        void boom(){}
        std::string gettypeID(){return "WATER";}
        void load(int,int,int,int,int,int,std::string);
        void draw();

    protected:
    private:
};

class waveCreator:public BaseCreator
{
public:
    waveCreator():BaseCreator(){}
    virtual ~waveCreator(){}
    GameObject*createGameObject()const
    {
        return new Waves();
    }
};
#endif // WAVES_H
