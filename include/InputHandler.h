#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include<iostream>
#include<SDL.h>
#include<vector>

#include"Game.h"
#include"Vector2D.h"

/* The following class is implemented as a singleton to handle mouse and keyboard events, every objects update function can
   check whether any event has happened using this and accordingly update its parameters , whenever this class' own update
   is called ,it updates the value of all happening events, the value of happening events is checked by gameObjects */
class InputHandler
{
    public:
        InputHandler();
        virtual ~InputHandler();
        static InputHandler* Instance();
        void update();
        void clean();
        bool getMouseButtonState(int buttonNumber);              /// returns true if a particular mouseButton is pressed
                                                                 /// the value true or false was set by update
        vector2D*getMousePosition();                             /// Function to return mousePosition
        bool isKeyDown(SDL_Scancode);                            /// returns true if a particular key is pressed


        void onMouseButtonUp(SDL_Event&);
        void onMouseButtonDown(SDL_Event&);
        void onMouseMotion(SDL_Event&);

        void reset();
    protected:
    private:
        static InputHandler* _instance;
        std::vector<bool>mousebuttonStates;                      /// This is an array of 3 elements , left-middle-right and
                                                                 /// true if a particular button is pressed
        vector2D*mousePosition;                                  /// a vector 2D type object to set the value of mouse Position
        const Uint8*keystates;                                   /// an array to hold state of all the keys
};

#endif // INPUTHANDLER_H
