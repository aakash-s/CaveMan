#ifndef ANIMATEGRAPHIC_H
#define ANIMATEGRAPHIC_H

#include <GameObject.h>
#include "GameObjectFactory.h"


class AnimateGraphic : public GameObject
{
    public:
        AnimateGraphic();
        virtual ~AnimateGraphic();
        void update();
        void draw();
        void clean();
        std::string getID();
        void load(int,int,int,int,int,int,std::string);
        std::string gettypeID(){return "ANIMATION";}
        void boom(){}
    protected:
    private:
};


class animCreator:public BaseCreator
{
public:
    animCreator():BaseCreator(){}
    virtual ~animCreator(){}
    GameObject*createGameObject()const
    {
        return new AnimateGraphic();
    }
};

#endif // ANIMATEGRAPHIC_H
