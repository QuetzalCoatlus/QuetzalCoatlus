#ifndef _PLAYERINPUT_H_
    #define _PLAYERINPUT_H_

#include "InputButton.h"

class PlayerInput
{
    public:
        static InputButton upButton;
        static InputButton downButton;
        static InputButton leftButton;
        static InputButton rightButton;
    
        static InputButton startButton;
        static InputButton selectButton;
    
        static InputButton attackButton;
        static InputButton jumpButton;
        static InputButton specialButton;
    
    private:
        PlayerInput();
    
    public:
        static void Initialize();
        static void HandleEvents(SDL_Event*);
    
    private:
        static void KeyDown(SDL_Keycode);
        static void KeyUp(SDL_Keycode);
};

#endif