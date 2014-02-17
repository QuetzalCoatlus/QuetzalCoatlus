#ifndef _GAMEENTITY_H_
	#define _GAMEENTITY_H_

#include <SDL2/SDL.h>

public class GameEntity
{
	private:
		SDL_Rect * entityBoundingBox;

	public:
		GameEntity(SDL_Rect*);

	public:
		bool CheckCollision(SDL_Rect *);
		bool CheckCollision(GameEntity*);

	public:
		SDL_Rect * GetBoundingBox();
};

#endif