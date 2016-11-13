#include "InputHandler.h"

InputHandler*InputHandler::_instance = 0;

InputHandler::InputHandler()
{
    for(int i = 0;i < 3;i++)
        mousebuttonStates.push_back(false);
    //ctor
    mousePosition = new vector2D(0.0,0.0);
}

InputHandler::~InputHandler()
{
    //dtor
}

InputHandler*InputHandler::Instance()
{
    if(_instance == 0){
        _instance = new InputHandler();
    }
    return _instance;
}

void InputHandler::reset()
{
    for(int i = 0;i < 3;i++)
        mousebuttonStates[i] = false;
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(keystates != 0){
        if(keystates[key] == 1)return true;
        else return false;
    }
    return false;
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
     if(event.button.button == SDL_BUTTON_LEFT)mousebuttonStates[0] = true;
     if(event.button.button == SDL_BUTTON_MIDDLE)mousebuttonStates[1] = true;
     if(event.button.button == SDL_BUTTON_RIGHT)mousebuttonStates[2] = true;
}

void InputHandler::onMouseButtonUp(SDL_Event&event)
{

    if(event.button.button == SDL_BUTTON_LEFT)mousebuttonStates[0] = false;
    if(event.button.button == SDL_BUTTON_MIDDLE)mousebuttonStates[1] = false;
    if(event.button.button == SDL_BUTTON_RIGHT)mousebuttonStates[2] = false;

}

void InputHandler::onMouseMotion(SDL_Event&event)
{
     mousePosition->setX(event.motion.x);
     mousePosition->setY(event.motion.y);
}

void InputHandler::update()
{
    SDL_Event event;
    keystates = SDL_GetKeyboardState(0);
    while(SDL_PollEvent(&event) == true)
    {
        if(event.type == SDL_MOUSEBUTTONDOWN){
              onMouseButtonDown(event);
        }
        if(event.type == SDL_MOUSEBUTTONUP){
              onMouseButtonUp(event);
        }
        if(event.type == SDL_MOUSEMOTION){
              onMouseMotion(event);
        }
        if(event.type == SDL_QUIT){
            Game::Instance()->quit();
        }
    }
}

void InputHandler::clean()
{

}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
    return mousebuttonStates[buttonNumber];
}

vector2D* InputHandler::getMousePosition()
{
    return mousePosition;
}



