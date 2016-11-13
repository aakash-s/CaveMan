#include "StateParser.h"
#include "Game.h"
#include "TextureManager.h"

StateParser::StateParser()
{
    //ctor
}

StateParser::~StateParser()
{
    //dtor
}

bool StateParser::parseState(const char*stateFile,std::string stateID,
                             std::vector<GameObject*>*stateObjects,std::vector<std::string>*loaded_textures)
{

    TiXmlDocument xmlDoc;
    xmlDoc.LoadFile(stateFile);

    TiXmlElement*docRoot = xmlDoc.RootElement();
    TiXmlElement*stateRoot = NULL;

    for(TiXmlElement*e = docRoot->FirstChildElement();e!=NULL;e=e->NextSiblingElement())
    {
        if(e->Value() == stateID)stateRoot = e;
    }

    for(TiXmlElement*e = stateRoot->FirstChildElement();e!=NULL;e=e->NextSiblingElement())
    {
        if(e->Value()==std::string("TEXTURES"))parseTextures(e,loaded_textures);

        if(e->Value()==std::string("OBJECTS"))parseObjects(e,stateObjects);
    }

    return true;
}

void StateParser::parseObjects(TiXmlElement*objectRoot,std::vector<GameObject*>*stateObjects)
{
    std::string type,id;
    int x,y,width,height,currentRow,currentFrame;
    for(TiXmlElement*e = objectRoot->FirstChildElement();e!=NULL;e=e->NextSiblingElement())
    {
        type = e->Attribute("type");
        id = e->Attribute("id");
        e->Attribute("x",&x);
        e->Attribute("y",&y);
        e->Attribute("width",&width);
        e->Attribute("height",&height);
        e->Attribute("currentRow",&currentRow);
        e->Attribute("currentFrame",&currentFrame);
        GameObject* _temp = GameObjectFactory::Instance()->create(type);
        _temp->load(x,y,width,height,currentRow,currentFrame,id);
        stateObjects->push_back(_temp);
    }
}

void StateParser::parseTextures(TiXmlElement*textureRoot,std::vector<std::string>*loaded_textures)
{
    std::string filename;
    std::string id;
    for(TiXmlElement*e = textureRoot->FirstChildElement();e!=NULL;e=e->NextSiblingElement())
    {
        filename = e->Attribute("filename");
        id = e->Attribute("id");
        TextureManager::Instance()->load(filename,id,Game::Instance()->getRenderer());
        loaded_textures->push_back(id);
    }
}


