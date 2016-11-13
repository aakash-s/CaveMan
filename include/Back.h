#ifndef BACK_H
#define BACK_H

#include <GameObject.h>
#include "Vector2D.h"
#include "GameObjectFactory.h"

class Back : public GameObject
{
    public:
        Back();
        virtual ~Back();
        void update();
        void draw();
        void clean();
        void load(int,int,int,int,int,int,std::string);
        std::string gettypeID(){return "BACK";}
        void setFrame(int a){currentFrame = a;}
        void boom(){}
    protected:
    private:

};

class backCreator:public BaseCreator
{
public:
    backCreator():BaseCreator(){}
    virtual ~backCreator(){}
    GameObject*createGameObject()const
    {
        return new Back();
    }
};
#endif // BACK_H
