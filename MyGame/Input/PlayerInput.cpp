#include "PlayerInput.h"

InputButton PlayerInput::upButton;
InputButton PlayerInput::downButton;
InputButton PlayerInput::leftButton;
InputButton PlayerInput::rightButton;
InputButton PlayerInput::startButton;
InputButton PlayerInput::selectButton;
InputButton PlayerInput::attackButton;
InputButton PlayerInput::jumpButton;
InputButton PlayerInput::specialButton;

PlayerInput::PlayerInput(){}

void PlayerInput::Initialize()
{
    upButton.button = SDLK_UP;
    downButton.button = SDLK_DOWN;
    leftButton.button = SDLK_LEFT;
    rightButton.button = SDLK_RIGHT;
    
    startButton.button = SDLK_g;
    selectButton.button = SDLK_f;
    
    attackButton.button = SDLK_d;
    jumpButton.button = SDLK_s;
    specialButton.button = SDLK_a;
}

void PlayerInput::HandleEvents(SDL_Event * event)
{
    	switch(event->type)
	{
        case SDL_KEYDOWN:
        {
            KeyDown(event->key.keysym.sym);
            break;
        }
        case SDL_KEYUP:
        {
            KeyUp(event->key.keysym.sym);
            break;
        }
	}
}

void PlayerInput::KeyDown(SDL_Keycode key)
{
    if(upButton.button == key)
        upButton.isPressed = true;
    if(downButton.button == key)
        downButton.isPressed = true;
    if(leftButton.button == key)
        leftButton.isPressed = true;
    if(rightButton.button == key)
        rightButton.isPressed = true;
    
    if(startButton.button == key)
        startButton.isPressed = true;
    if(selectButton.button == key)
        selectButton.isPressed = true;
    
    if(attackButton.button == key)
        attackButton.isPressed = true;
    if(jumpButton.button == key)
        jumpButton.isPressed = true;
    if(specialButton.button == key) specialButton.isPressed = true;
}

void PlayerInput::KeyUp(SDL_Keycode key)
{
    if(upButton.button == key)
        upButton.isPressed = false;
    if(downButton.button == key)
        downButton.isPressed = false;
    if(leftButton.button == key)
        leftButton.isPressed = false;
    if(rightButton.button == key)
        rightButton.isPressed = false;
    
    if(startButton.button == key)
        startButton.isPressed = false;
    if(selectButton.button == key)
        selectButton.isPressed = false;
    
    if(attackButton.button == key)
        attackButton.isPressed = false;
    if(jumpButton.button == key)
        jumpButton.isPressed = false;
    if(specialButton.button == key) specialButton.isPressed = false;
}