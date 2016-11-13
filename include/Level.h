#ifndef LEVEL_H
#define LEVEL_H
#include<iostream>
#include<vector>
#include "Layer.h"
#include "GameObject.h"


struct Tileset
{
    int firstGID;
    int tileWidth;
    int tileHeight;
    int width;
    int height;
    int spacing;
    int margin;
    int num_cols;
    std::string name;
};

class Level
{
    public:

        virtual ~Level();
        void update();
        void render();
        std::vector<Tileset>*getTilesets()
        {
            return &tilesets;
        }
        std::vector<Layer*>*getLayers()
        {
            return &layers;
        }
        std::vector<Layer*>*getc_Layers()
        {
            return &c_layers;
        }
        GameObject* get_player()
        {
            return _hero;
        }
        void setPlayer(GameObject* p)
        {
            _hero = p;
        }
        std::string get_playerID()const
        {
            return _hero->getID();
        }
    protected:
    private:
        friend class LevelParser;
        Level();
        std::vector<Tileset>tilesets;
        std::vector<Layer*>layers;
        std::vector<Layer*>c_layers;
        GameObject*_hero;
};

#endif // LEVEL_H
