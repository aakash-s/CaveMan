#include "PauseState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "PauseState.h"
#include "StateParser.h"


PauseState::PauseState()
{
    stateID = "PAUSE";
    //ctor
}

PauseState::~PauseState()
{
    //dtor
}

void PauseState::update()
{
    for(int i=0;i<stateObjects.size();i++)
        stateObjects[i]->update();
}

void PauseState::render()
{
    for(int i=0;i<stateObjects.size();i++)
        stateObjects[i]->draw();
}

bool PauseState::onEnter()
{
    StateParser _parser;
    _parser.parseState("stateData.xml","PAUSE",&stateObjects,&loaded_textures);
   return true;
}

bool PauseState::onExit()
{
    for(int i=0;i<stateObjects.size();i++)stateObjects[i]->clean();
    stateObjects.clear();
    for(int i=0;i<loaded_textures.size();i++)TextureManager::Instance()->clearFromTextureMap(loaded_textures[i]);
    loaded_textures.clear();
    InputHandler::Instance()->reset();
}
