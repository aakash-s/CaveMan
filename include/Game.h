#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL.h>

#include"InputHandler.h"
#include"GameState.h"
#include"GameStateMachine.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void update();
        void render();
        bool init(const char*title,int xpos,int ypos,int width,int height);
        static Game* Instance();
        void clean();
        bool running();
        void quit();
        void register_types();
        SDL_Renderer*getRenderer();
        GameStateMachine*getGameStateMachine(){return gameStateMachine;}
        int getGameWidth()const;
        int getGameHeight()const;
        void sounds();
    protected:
    private:
        SDL_Window*window;
        SDL_Renderer*renderer;
        bool run_status;
        static Game*_instance;
        GameStateMachine*gameStateMachine;
        int gameWidth;
        int gameHeight;
};

#endif // GAME_H
