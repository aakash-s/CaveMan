#ifndef STATEPARSER_H
#define STATEPARSER_H
#include "GameObject.h"
#include <vector>
#include "Tinyxml.h"
#include "GameObjectFactory.h"

class StateParser
{
    public:
        StateParser();
        virtual ~StateParser();
        bool parseState(const char*stateFile,std::string stateID,
                        std::vector<GameObject*>*stateObjects,std::vector<std::string>*loaded_textures);
    protected:
    private:
        void parseObjects(TiXmlElement*ObjectRoot,std::vector<GameObject*>*stateObjects);
        void parseTextures(TiXmlElement*textureRoot,std::vector<std::string>*loaded_textures);
};

#endif // STATEPARSER_H
