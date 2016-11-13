#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <GameState.h>


class GameOverState : public GameState
{
    public:
        GameOverState();
        virtual ~GameOverState();
        void update();
        void render();
        bool onEnter();
        bool onExit();
    protected:
    private:
};

#endif // GAMEOVERSTATE_H
