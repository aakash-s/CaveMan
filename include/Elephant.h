#ifndef ELEPHANT_H
#define ELEPHANT_H

#include <GameObject.h>
#include "GameObjectFactory.h"

class Elephant : public GameObject
{
    public:
        Elephant();
        virtual ~Elephant();
        void draw();
        void update();
        void clean();
        void boom();
        std::string getID(){return ID;}
        std::string gettypeID(){return "ENEMY";}
        void load(int,int,int,int,int,int,std::string);
        void handleInput();
        void handleMovement(vector2D);
    protected:
    private:
        bool moveLeft;
        bool moveRight;
        int wait;
        int num_frames;
};

class ElephantCreator:public BaseCreator
{
public:
    ElephantCreator():BaseCreator(){}
    virtual ~ElephantCreator(){}
    GameObject*createGameObject()const
    {
        return new Elephant();
    }
};
#endif // ELEPHANT_H
