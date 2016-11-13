#ifndef TILELAYER_H
#define TILELAYER_H
#include "Level.h"
#include <Layer.h>

#include "vector2D.h"

class TileLayer : public Layer
{
    public:
        TileLayer(int tilesize,const std::vector<Tileset> &_tilesets,int gameWidth,int gameHeight);
        virtual ~TileLayer();
        void update();
        void render();
        void setTileIDs(std::vector<std::vector<int>>data)
        {
            tileIDs = data;
        }
        void setTilesize(int _tilesize)
        {
            tilesize = _tilesize;
        }
        std::vector<std::vector<int>> getTileIDs()
        {
            return tileIDs;
        }
        Tileset getTilesetByID(int tileID);
        vector2D getPosition()
        {
            return position;
        }
        int getTileSize()
        {
            return tilesize;
        }
        void change(int a,int b)
        {
            tileIDs[a][b]=0;
        }
    protected:
    private:
        std::vector<std::vector<int>>tileIDs;
        const std::vector<Tileset>&tilesets;        /// reference to an already declared vector of Level class
        int tilesize;
        int num_rows;
        int num_cols;
        vector2D position,velocity;
        int gameWidth;
        int gameHeight;

};

#endif // TILELAYER_H
