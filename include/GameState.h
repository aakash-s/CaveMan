#ifndef GAMESTATE_H
#define GAMESTATE_H
#include<iostream>
#include<vector>
#include "GameObject.h"
#include "StateParser.h"

/** Abstract base class for Game States */
class GameState
{
    public:
        GameState();
        virtual ~GameState();
        virtual void update() = 0;
        virtual void render() = 0;
        virtual bool onEnter() = 0;
        virtual bool onExit() = 0;
        virtual std::string getStateID();
    protected:
        std::vector<std::string>loaded_textures;
        std::vector<GameObject*>stateObjects;
        std::string stateID;
    private:
};

#endif // GAMESTATE_H
