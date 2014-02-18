#ifndef _SDLRECTCOLLISION_H_
    #define _SDLRECTCOLLISION_H_

#include <SDL.h>

class SdlRectCollision
{
	private:
		SdlRectCollision();

	public:
		static bool Collides(SDL_Rect*, SDL_Rect*);
};

#endif