#ifndef SNAIL_H
#define SNAIL_H

#include <GameObject.h>
#include "GameObjectFactory.h"


class Snail : public GameObject
{
    public:
        Snail();
        virtual ~Snail();
        void update();
        void draw();
        void clean();
        std::string gettypeID(){return "ENEMY";}
        void load(int xpos,int ypos,int width,int height,int currentRow,int currentFrame,std::string ID);
        void handleMovement(vector2D);
        void boom();
    protected:
    private:
        bool moveLeft;
        bool moveRight;
        int dyingCounter;
};

class snailCreator:public BaseCreator
{
public:
    snailCreator():BaseCreator(){}
    virtual ~snailCreator(){}
    GameObject*createGameObject()const
    {
        return new Snail();
    }
};
#endif // SNAIL_H
