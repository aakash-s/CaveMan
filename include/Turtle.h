#ifndef TURTLE_H
#define TURTLE_H

#include <GameObject.h>
#include"GameObjectFactory.h"

class Turtle : public GameObject
{
    public:
        Turtle();
        virtual ~Turtle();
        void update();
        void clean(){}
        void boom(){}
        void draw();
        std::string gettypeID(){return "ENEMY";}
        void load(int,int,int,int,int,int,std::string);
        void handleMovement(vector2D);

    protected:
    private:
        bool moveLeft;
        bool moveRight;
};

class turtleCreator:public BaseCreator
{
public:
    turtleCreator():BaseCreator(){}
    virtual ~turtleCreator(){}
    GameObject*createGameObject()const
    {
        return new Turtle();
    }
};



#endif // TURTLE_H
