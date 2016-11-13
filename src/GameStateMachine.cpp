#include "GameStateMachine.h"

GameStateMachine::GameStateMachine()
{
    //ctor
}

GameStateMachine::~GameStateMachine()
{
    //dtor
}

GameState* GameStateMachine::return_last_state()
{
    return gameStates.back();
}

void GameStateMachine::pushState(GameState*State)
{
    gameStates.push_back(State);               /// State is added
    gameStates.back()->onEnter();                 /// onEnter of added state is called
}

void GameStateMachine::popState()
{
    gameStates.back()->onExit();
    gameStates.pop_back();
}

void GameStateMachine::changeState(GameState* state)
{
    if( !gameStates.empty() ){
        if( gameStates.back()->getStateID() == state->getStateID() ){
           return;
        }
        if( gameStates.back()->onExit() ){
            std::cout<<gameStates.back()->getStateID()<<"\n";
            gameStates.back() = NULL;
            gameStates.pop_back();
        }
    }
    gameStates.push_back(state);
    gameStates.back()->onEnter();
}
