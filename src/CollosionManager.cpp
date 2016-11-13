#include "CollosionManager.h"
#include "TileLayer.h"
#include "Collosion.h"
#include "Game.h"

CollosionManager*CollosionManager::_instance = 0;

CollosionManager*CollosionManager::Instance()
{
    if(_instance == 0)_instance = new CollosionManager();
    return _instance;
}

CollosionManager::CollosionManager()
{
   // wait = 115;
   wait = 46;
    //ctor
}

CollosionManager::~CollosionManager()
{
    //dtor
}

bool CollosionManager::checkPlayerTileCollosion(vector2D newPos,int width,int height)
{
    for(std::vector<Layer*>::const_iterator it = c_layers->begin();it!=c_layers->end();it++)
    {
        if(newPos.getY()+height >= Game::Instance()->getGameHeight()-16)return false;
        Layer* _tilelayer = (*it);
        std::vector<std::vector<int>>tiles = (_tilelayer->getTileIDs());
        vector2D layerPos = _tilelayer->getPosition();
        int x,y,tileCol,tileRow,tileID = 0;
        x = layerPos.getX()/_tilelayer->getTileSize();
        y = layerPos.getY()/_tilelayer->getTileSize();

        vector2D startPos = newPos;
        startPos.setX(startPos.getX()+15);
        startPos.setY(startPos.getY()+20);

        vector2D endPos(newPos.getX()+width-15,newPos.getY()+height-5);
        for(int i=startPos.getX();i<endPos.getX();i++)
        {
            for(int j=startPos.getY();j<endPos.getY();j++)
            {
                tileCol = i/_tilelayer->getTileSize();
                tileRow = j/_tilelayer->getTileSize();
                tileID = tiles[tileRow+y][tileCol+x];
                if(tileID != 0)
                    {
                        if(tileID == 558 or tileID == 559){
                                wait--;
                                if(wait%2==0)
                                _tilelayer->change(tileRow+y,tileCol+x);

                        }
                        if(tileID == 491 or tileID==492 or tileID==493)
                        {
                            hero->boom();
                        }
                        return true;
                    }

            }
        }


    }
    return false;
}


void CollosionManager::checkPlayerEnemeyCollosion(GameObject*hero,std::vector<GameObject*>&stateObjects)
{
    SDL_Rect* Prect1 = new SDL_Rect();
    Prect1->x = hero->getpos().getX();
    Prect1->y = hero->getpos().getY();
    Prect1->w = hero->getWidth();
    Prect1->h = hero->getHeight();

    for(int i = 0;i < stateObjects.size();i++)
    {

        if(stateObjects[i]->gettypeID() != std::string("ENEMY") and
           stateObjects[i]->gettypeID() != std::string("PICKUP"))continue;
        SDL_Rect*Erect2 = new SDL_Rect();
        Erect2->x = stateObjects[i]->getpos().getX();
        Erect2->y = stateObjects[i]->getpos().getY();
        Erect2->w = stateObjects[i]->getWidth();
        Erect2->h = stateObjects[i]->getHeight();
        if(Collosion::Instance()->collided(Prect1,Erect2))           /// There is a collosion
        {
            if(stateObjects[i]->gettypeID() == std::string("PICKUP")){

                    hero->setHealth((hero->getHealth()+50));
                    if(hero->getHealth()>100)hero->setHealth(100);
                    stateObjects[i]->boom();
                    }
            if(hero->getRow()!=1)
            hero->boom();
            else if(hero->getFrame()!=7)
            stateObjects[i]->boom();
            if(stateObjects[i]->getID()==std::string("elephant"))stateObjects[i]->boom();
             if(stateObjects[i]->getID()==std::string("dragon"))stateObjects[i]->boom();
              if(stateObjects[i]->getID()==std::string("lion"))stateObjects[i]->boom();
        }
    }

}







