#include "MenuButton.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PlayState.h"
#include "SoundManager.h"
#include "MenuState.h"

MenuButton::MenuButton()
{
    //ctor
}

MenuButton::~MenuButton()
{
    //dtor
}

void MenuButton::update()
{

    currentFrame = 0;
    vector2D*mouse_pos = InputHandler::Instance()->getMousePosition();
    if( mouse_pos->getX() < (position.getX() + width) and mouse_pos->getX() > position.getX() and
        mouse_pos->getY() < (position.getY() + height) and mouse_pos->getY() > position.getY() )
    {
        currentFrame = 1;
        if( InputHandler::Instance()->getMouseButtonState(0) )
        {
            currentFrame = 2;
            if(ID == "exit")
                {
                    Game::Instance()->quit();
                }
            else if(ID == "playButton")
                {
                    SoundManager::Instance()->playMusic("background",-1);
                    Game::Instance()->getGameStateMachine()->changeState(new PlayState());
                }
            else if(ID == "main")
                {
                    Game::Instance()->getGameStateMachine()->changeState(new MenuState());
                }
            else if(ID == "resume")
                {
                    Game::Instance()->getGameStateMachine()->popState();
                }
            else if(ID == "restart")
                {
                    Game::Instance()->getGameStateMachine()->changeState(new PlayState());
                }
        }
    }
}


void MenuButton::load(int xpos,int ypos,int _width,int _height,int _cR,int _cF,std::string _ID)
{
    velocity.setX(0);velocity.setY(0);
    acceleration.setX(0);acceleration.setY(0);
    position.setX(xpos);
    position.setY(ypos);
    width = _width;
    height = _height;
    ID = _ID;
    currentRow = _cR;
    currentFrame = _cF;
    flip = 0;
    dead = false;
}

void MenuButton::draw()
{
    GameObject::draw();
}

void MenuButton::clean()
{


}
