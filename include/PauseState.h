#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <GameState.h>


class PauseState : public GameState
{
    public:
        PauseState();
        virtual ~PauseState();
        void update();
        void render();
        bool onExit();
        bool onEnter();
    protected:
    private:
};

#endif // PAUSESTATE_H
