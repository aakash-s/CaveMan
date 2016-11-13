#ifndef COLLOSIONMANAGER_H
#define COLLOSIONMANAGER_H
#include "Collosion.h"
#include "Level.h"
#include "GameObject.h"
#include "GameState.h"


class CollosionManager
{
    public:
        CollosionManager();
        virtual ~CollosionManager();
        bool checkPlayerTileCollosion(vector2D newPos,int,int);
        static CollosionManager* Instance();
        void setLayers(std::vector<Layer*>*layers)
        {
            c_layers = layers;
        }
        void checkPlayerEnemeyCollosion(GameObject*hero,std::vector<GameObject*>&stateObjects);
        void sethero(GameObject*a)
        {
            hero = a;
        }
    protected:
    private:
        static CollosionManager*_instance;
        std::vector<Layer*>*c_layers;
        int wait;
        GameObject*hero;
};

#endif // COLLOSIONMANAGER_H
