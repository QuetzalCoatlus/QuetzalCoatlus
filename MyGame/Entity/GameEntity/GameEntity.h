#ifndef _GAMEENTITY_H_
	#define _GAMEENTITY_H_

#include <SDL.h>
#include "SdlRectCollision.h"

class GameEntity : Entity
{
	public:
		GameEntity(SDL_Rect*);

	public:
		void Load();
		void Update();
		bool Render();
		void Destroy();

	public:
		void Move();
		void StopMotion();

	public:
		void HandleCollision();
};

#endif