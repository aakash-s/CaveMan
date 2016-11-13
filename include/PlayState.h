#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <GameState.h>
#include "GameObject.h"
#include "Level.h"


class PlayState : public GameState
{
    public:
        PlayState();
        virtual ~PlayState();
        bool onEnter();
        bool onExit();
        void update();
        void render();
    protected:
    private:
        Level*_level;
        GameObject*hero;
};

#endif // PLAYSTATE_H
