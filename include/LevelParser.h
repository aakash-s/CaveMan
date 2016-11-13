#ifndef LEVELPARSER_H
#define LEVELPARSER_H
#include"Level.h"
#include"tinyxml.h"
#include<iostream>
#include<vector>
#include "GameObject.h"


class LevelParser
{
    public:
        LevelParser();
        virtual ~LevelParser();
        Level* parseLevel(const char*levelFile);
    protected:
    private:
        void parseTilesets(TiXmlElement*tilesetRoot,std::vector<Tileset>*tilesets);
        void parseTileLayer(TiXmlElement*tilelayerRoot,std::vector<Layer*>*layers,std::vector<Layer*>*c_layers,
                            std::vector<Tileset>*tilesets,
                            int gameWidth,int gameHeight);
        int tilesize;
        int width;
        int height;
};

#endif // LEVELPARSER_H
