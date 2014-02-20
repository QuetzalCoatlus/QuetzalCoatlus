#ifndef _GAMEENTITY_H_
	#define _GAMEENTITY_H_

#include <SDL.h>
#include <string>

#include "Entity.h"
#include "GameTexture.h"
#include "GameFps.h"
#include "GameAnimation.h"
#include "SdlRectCollision.h"
class GameEntity : public Entity
{
    private:
        GameTexture * entityTexture;
        GameAnimation * entityAnimation;
    
    private:
        float xVelocity;
        float yVelocity;
    
    public:
        bool isMovingLeft;
        bool isMovingRight;
        bool isMovingUp;
        bool isMovingDown;

	public:
		GameEntity(int,int);

	public:
		bool Load(std::string,SDL_Renderer*);
		void Update();
		void Render(SDL_Renderer*);
		void Destroy();

	public:
		void Move();

	public:
		void HandleCollision();
};

#endif