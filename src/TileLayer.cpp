#include "TileLayer.h"
#include "TextureManager.h"
#include "Game.h"
#include "CollosionManager.h"
#include "Camera.h"

TileLayer::TileLayer(int _tilesize,const std::vector<Tileset>&_tileset
                     ,int gameWidth,int gameHeight):tilesets(_tileset),tilesize(_tilesize),position(0,0)
                    ,velocity(0,0)
{
    num_cols = Game::Instance()->getGameWidth()/tilesize;
    num_rows = Game::Instance()->getGameHeight()/tilesize;
    num_rows = gameHeight;
    num_cols = gameWidth;
    //ctor
}

TileLayer::~TileLayer()
{
    //dtor
}

void TileLayer::update()
{

}

void TileLayer::render()
{
    int x,y,x2,y2;
    x = position.getX()/tilesize;
    y = position.getY()/tilesize;
    x2 = (int(position.getX()))%tilesize;
    y2 = (int(position.getY()))%tilesize;

    for(int i=0;i<num_rows;i++)
    {
        for(int j=0;j<num_cols;j++)
        {
            int ID = tileIDs[i][j+x];
            if(ID == 0)continue;
            if( ( ((j*tilesize)-x2)-Camera::Instance()->getPosition().getX() < -tilesize ) or
                ( ((j*tilesize)-x2))-Camera::Instance()->getPosition().getX() > Game::Instance()->getGameWidth()
                ) continue;
            Tileset tileset = getTilesetByID(ID);
            ID--;
            TextureManager::Instance()->drawTile(tileset.name,tileset.margin,tileset.spacing,
                                                 (j*tilesize)-x2-Camera::Instance()->getPosition().getX(),
                                                 (i*tilesize)-y2,tilesize,tilesize,
                                                 (ID-(tileset.firstGID-1))/tileset.num_cols,
                                                 (ID-(tileset.firstGID-1))%tileset.num_cols,
                                                 Game::Instance()->getRenderer());

        }
    }
}


Tileset TileLayer::getTilesetByID(int ID)
{
    for(int i=0;i<tilesets.size();i++)
    {
        if(i+1<=tilesets.size()-1)
        {
            if(ID >= tilesets[i].firstGID and ID<tilesets[i+1].firstGID){
                return tilesets[i];
            }
        }
        else {
            return tilesets[i];
        }
    }
    std::cout<<"Did not find Tileset ! RETURNING NULL TILESET!!\n";
    Tileset t;
    return t;
}


