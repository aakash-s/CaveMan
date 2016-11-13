#include "PlayState.h"
#include "Player.h"
#include "Game.h"
#include "GameStateMachine.h"
#include "PauseState.h"
#include "LevelParser.h"
#include "Snail.h"
#include "CollosionManager.h"
#include "Back.h"
#include "StateParser.h"
PlayState::PlayState()
{
    stateID = "PLAY";
    //ctor
}

PlayState::~PlayState()
{
    //dtor
}

void PlayState::update()
{
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
        Game::Instance()->getGameStateMachine()->pushState(new PauseState());
    }
    _level->update();
    for(int i =0;i<stateObjects.size();i++){
          if(stateObjects[i]->isDead()){
                stateObjects.erase(stateObjects.begin()+i);
                continue;
          }
          stateObjects[i]->update();
    }

    CollosionManager::Instance()->checkPlayerEnemeyCollosion(_level->get_player(),stateObjects);
}
void PlayState::render()
{
    for(int i=0;i<stateObjects.size();i++)
        {
            if(stateObjects[i]->gettypeID() == string("BACK"))stateObjects[i]->draw();
        }
    _level->render();
    for(int i=0;i<stateObjects.size();i++)
        {
            if(stateObjects[i]->gettypeID() == string("BACK"))continue;
            stateObjects[i]->draw();
        }
}

bool PlayState::onEnter()
{
    LevelParser _level_parser;
    _level = _level_parser.parseLevel("map_2.tmx");
    hero = _level->get_player();
    loaded_textures.push_back(hero->getID());
    stateObjects.push_back(hero);

    StateParser _parser;
    _parser.parseState("stateData.xml","PLAY",&stateObjects,&loaded_textures);

    for(int i=0;i<stateObjects.size();i++)
        stateObjects[i]->sethero(hero);
}

bool PlayState::onExit()
{
    for(int i=0;i<stateObjects.size();i++)stateObjects[i]->clean();
    stateObjects.clear();
    for(int i=0;i<loaded_textures.size();i++)TextureManager::Instance()->clearFromTextureMap(loaded_textures[i]);
    loaded_textures.clear();
    InputHandler::Instance()->reset();
}

