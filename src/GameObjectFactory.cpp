#include "GameObjectFactory.h"

GameObjectFactory*GameObjectFactory::_instance = 0;

GameObjectFactory::GameObjectFactory()
{
    //ctor
}

GameObjectFactory::~GameObjectFactory()
{
    //dtor
}

bool GameObjectFactory::registerType(std::string typeID,BaseCreator*_creators)
{
    std::map<std::string,BaseCreator*>::iterator it = creators.find(typeID);
    if(it != creators.end())
    {
        delete _creators;
        return false;
    }
    creators[typeID] = _creators;
    return true;
}

GameObjectFactory*GameObjectFactory::Instance()
{
    if(_instance == 0)_instance = new GameObjectFactory();
    return _instance;
}


GameObject*GameObjectFactory::create(std::string typeID)
{
    std::map<std::string,BaseCreator*>::iterator it = creators.find(typeID);
    if(it == creators.end())
    {
        std::cout<<"Could not find type "<<typeID<<"ID";
        return NULL;
    }
    BaseCreator* _creator = (*it).second;
    return _creator->createGameObject();
}
