#ifndef _GAMEENTITY_H_
	#define _GAMEENTITY_H_

#include <SDL.h>
#include "SdlRectCollision.h"

class GameEntity
{
	private:
		SDL_Rect * entityBoundingBox;
    
	public:
		GameEntity(SDL_Rect*);
    
    public:
        bool hasBeenUpdated;

	public:
		bool CheckCollision(SDL_Rect *);
		bool CheckCollision(GameEntity*);
        bool NeedsUpdate();
    
public:
		SDL_Rect * GetBoundingBox();
};

#endif