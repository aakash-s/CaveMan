#include "Game.h"
#include "MenuState.h"
#include "GameOverState.h"
#include "GameObjectFactory.h"
#include "MenuButton.h"
#include "Snail.h"
#include "Back.h"
#include "AnimateGraphic.h"
#include "HealthBar.h"
#include "hammerMan.h"
#include "Elephant.h"
#include "Waves.h"
#include "Turtle.h"
#include "SoundManager.h"
#include "Candy.h"

Game*Game::_instance = 0;

Game::Game()
{
    window = NULL;
    renderer = NULL;
    run_status = false;
    //ctor
}

Game::~Game()
{
    //dtor
}

bool Game::init(const char*title,int xpos,int ypos,int width,int height)
{
    gameWidth = width;
    gameHeight = height;
    if( SDL_Init(SDL_INIT_EVERYTHING) != 0 )
    {
        std::cout<<"SDL Initialization Failed !"<<SDL_GetError()<<"\n";
        return false;
    }
    window = SDL_CreateWindow(title,xpos,ypos,width,height,SDL_WINDOW_FULLSCREEN);
    if( window == NULL)
    {
        std::cout<<"Window Initialization Failed !"<<SDL_GetError()<<"\n";
        return false;
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
    if( renderer == NULL)
    {
        std::cout<<"Renderer Initialization Failed !"<<SDL_GetError()<<"\n";
        return false;
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    register_types();
    gameStateMachine = new GameStateMachine();
    gameStateMachine->pushState(new MenuState());
    sounds();
    run_status = true;
    return run_status;
}

void Game::register_types()
{
    GameObjectFactory::Instance()->registerType("MenuButton",new menuButtonCreator());
    GameObjectFactory::Instance()->registerType("background",new backCreator());
    GameObjectFactory::Instance()->registerType("snail",new snailCreator());
    GameObjectFactory::Instance()->registerType("Animation",new animCreator());
    GameObjectFactory::Instance()->registerType("health",new healthCreator());
    GameObjectFactory::Instance()->registerType("hammerMan",new hammerManCreator());
    GameObjectFactory::Instance()->registerType("Elephant",new ElephantCreator());
    GameObjectFactory::Instance()->registerType("Water",new waveCreator());
    GameObjectFactory::Instance()->registerType("Turtle",new turtleCreator());
    GameObjectFactory::Instance()->registerType("Pickup",new pickupCreator());
}
void Game::sounds()
{
    if(!SoundManager::Instance()->load("assets/caravan.ogg.ogg","background",SOUND_MUSIC))std::cout<<"ERROR\n";
    if(!SoundManager::Instance()->load("assets/test.ogg","attack",SOUND_SFX))std::cout<<"ERROR\n";
    if(!SoundManager::Instance()->load("assets/round_end.wav","level",SOUND_SFX))std::cout<<"ERROR\n";
     if(!SoundManager::Instance()->load("assets/metalClick.ogg","enemy",SOUND_SFX))std::cout<<"ERROR\n";
    if(!SoundManager::Instance()->load("assets/death.wav","death",SOUND_SFX))std::cout<<"ERROR\n";
     if(!SoundManager::Instance()->load("assets/jumppp22.ogg","jump",SOUND_SFX))std::cout<<"ERROR\n";
     if(!SoundManager::Instance()->load("assets/3.wav","ele",SOUND_SFX))std::cout<<"ERROR\n";
      if(!SoundManager::Instance()->load("assets/1.wav","roar",SOUND_SFX))std::cout<<"ERROR\n";


}
void Game::render()
{
    SDL_RenderClear(renderer);
    gameStateMachine->return_last_state()->render();
    SDL_RenderPresent(renderer);
}

void Game::update()
{
    gameStateMachine->return_last_state()->update();
    InputHandler::Instance()->update();
}

Game*Game::Instance()
{
    if( _instance == 0)_instance = new Game();
    return _instance;
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


int Game::getGameWidth()const
{
    return gameWidth;
}

int Game::getGameHeight()const
{
    return gameHeight;
}


bool Game::running()
{
    return run_status;
}

void Game::quit()
{
    run_status = false;
}

SDL_Renderer* Game::getRenderer()
{
    return renderer;
}
