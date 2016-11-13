#ifndef GAMEWON_H
#define GAMEWON_H

#include <GameState.h>


class GameWon : public GameState
{
     public:
        GameWon();
        virtual ~GameWon();
        void update();
        void render();
        bool onEnter();
        bool onExit();
    protected:
    private:
};

#endif // GAMEWON_H
