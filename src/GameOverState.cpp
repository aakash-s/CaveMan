#include "GameOverState.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Game.h"
#include "AnimateGraphic.h"
#include "StateParser.h"


GameOverState::GameOverState()
{
    stateID = "GAMEOVER";
    //ctor
}

GameOverState::~GameOverState()
{
    //dtor
}

void GameOverState::update()
{
    for(int i=0;i<stateObjects.size();i++)
        stateObjects[i]->update();
}

void GameOverState::render()
{
    for(int i=0;i<stateObjects.size();i++)
        stateObjects[i]->draw();
}

bool GameOverState::onEnter()
{
    StateParser _parser;
    _parser.parseState("stateData.xml","GAMEOVER",&stateObjects,&loaded_textures);
    return true;
}

bool GameOverState::onExit()
{
    for(int i=0;i<stateObjects.size();i++)stateObjects[i]->clean();
    stateObjects.clear();
    for(int i=0;i<loaded_textures.size();i++)TextureManager::Instance()->clearFromTextureMap(loaded_textures[i]);
    loaded_textures.clear();
    InputHandler::Instance()->reset();
}
