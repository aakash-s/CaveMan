#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <GameObject.h>
#include "GameObjectFactory.h"

class MenuButton : public GameObject
{
    public:
        MenuButton();
        virtual ~MenuButton();
        void update();
        void draw();
        void clean();
        void load(int,int,int,int,int,int,std::string);
        std::string gettypeID(){return "BUTTON";}
        void boom(){}
    protected:
    private:
};


class menuButtonCreator:public BaseCreator
{
public:
    menuButtonCreator():BaseCreator(){}
    virtual ~menuButtonCreator(){}
    GameObject*createGameObject()const
    {
        return new MenuButton();
    }
};
#endif // MENUBUTTON_H
