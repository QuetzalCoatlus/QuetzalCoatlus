#ifndef _INPUTBUTTON_H_
    #define _INPUTBUTTON_H_

#include <SDL.h>

class InputButton
{
    public:
       SDL_Keycode button;
       bool isPressed;
    
    public:
        InputButton();
    
};

#endif