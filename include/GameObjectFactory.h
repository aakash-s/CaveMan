#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#include<string>
#include<map>
#include"GameObject.h"

class BaseCreator
{
public:
    BaseCreator(){}
    virtual GameObject* createGameObject()const=0;

    virtual ~BaseCreator(){}
};

class GameObjectFactory
{
    public:
        GameObjectFactory();
        virtual ~GameObjectFactory();
        bool registerType(std::string,BaseCreator*);
        GameObject*create(std::string);
        static GameObjectFactory*Instance();
    protected:
    private:
        std::map<std::string,BaseCreator*>creators;
        static GameObjectFactory*_instance;
};

#endif // GAMEOBJECTFACTORY_H
