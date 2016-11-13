#include "MenuState.h"
#include "MenuButton.h"
#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

MenuState::MenuState()
{
    stateID = "MENU";
    //ctor
}

MenuState::~MenuState()
{
    //dtor
}

void MenuState::render()
{
    for(int i=0;i<stateObjects.size();i++){
        stateObjects[i]->draw();
    }
}

void MenuState::update()
{
    for(int i=0;i<stateObjects.size();i++){
        stateObjects[i]->update();
    }
}

bool MenuState::onEnter()
{
    StateParser _parser;
    _parser.parseState("stateData.xml","MENU",&stateObjects,&loaded_textures);
}

bool MenuState::onExit()
{
    for(int i=0;i<stateObjects.size();i++)stateObjects[i]->clean();
    stateObjects.clear();
    for(int i=0;i<loaded_textures.size();i++)
    {
        TextureManager::Instance()->clearFromTextureMap(loaded_textures[i]);
    }
    loaded_textures.clear();
    InputHandler::Instance()->reset();
}
