#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <GameState.h>


class MenuState : public GameState
{
    public:
        MenuState();
        virtual ~MenuState();
        void update();
        void render();
        bool onExit();
        bool onEnter();
    protected:
    private:
};

#endif // MENUSTATE_H
