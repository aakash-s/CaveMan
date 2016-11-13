#include "GameWon.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Game.h"
#include "AnimateGraphic.h"
#include "StateParser.h"


GameWon::GameWon()
{
    stateID = "GAMEOVER";
    //ctor
}

GameWon::~GameWon()
{
    //dtor
}

void GameWon::update()
{
    for(int i=0;i<stateObjects.size();i++)
        stateObjects[i]->update();
}

void GameWon::render()
{
    for(int i=0;i<stateObjects.size();i++)
        stateObjects[i]->draw();
}

bool GameWon::onEnter()
{
    StateParser _parser;
    _parser.parseState("stateData.xml","GAMEWON",&stateObjects,&loaded_textures);
    return true;
}

bool GameWon::onExit()
{
    for(int i=0;i<stateObjects.size();i++)stateObjects[i]->clean();
    stateObjects.clear();
    for(int i=0;i<loaded_textures.size();i++)TextureManager::Instance()->clearFromTextureMap(loaded_textures[i]);
    loaded_textures.clear();
    InputHandler::Instance()->reset();
}
