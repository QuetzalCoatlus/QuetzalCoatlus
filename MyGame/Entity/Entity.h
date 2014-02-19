#ifndef _ENTITY_H_
	#define _ENTITY_H_

#include <SDL.h>
#include "SdlRectCollision.h"

class Entity
{
	private:
		SDL_Rect * entityBoundingBox;
    
	public:
		Entity(SDL_Rect*);
    
    public:
        bool hasBeenUpdated;

	public:
		bool CheckCollision(SDL_Rect *);
		bool CheckCollision(Entity*);
        bool NeedsUpdate();
    
public:
		SDL_Rect * GetBoundingBox();
};

#endif