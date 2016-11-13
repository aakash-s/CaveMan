#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H
#include"GameState.h"
#include<iostream>
#include<vector>
/* This class is used to implement the functions required to load a particular state, change a state or unload a state
   All this will be accomplished using GameState type pointers */

class GameStateMachine
{
    public:
        GameStateMachine();
        virtual ~GameStateMachine();
        void pushState(GameState*);          /// Add a state without removing the previous state
        void changeState(GameState*);        /// Remove a state and add another state
        void popState();                     /// Removes a state
        GameState*return_last_state();        /// Returns current state
    protected:
    private:
        std::vector<GameState*> gameStates;
};

#endif // GAMESTATEMACHINE_H
