#ifndef _GAMEENTITY_H_
	#define _GAMEENTITY_H_

#include <SDL.h>
#include <string>
#include <math.h>

#include "Entity.h"
#include "GameTexture.h"
#include "GameFps.h"
#include "PlayerInput.h"
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
        float zVelocity;
    
    private:
        int currentFrameState;
    
    public:
        bool isMovingLeft;
        bool isMovingRight;
        bool isMovingUp;
        bool isMovingDown;
    
        bool isFacingLeft;
        bool isFacingRight;
    
        bool isJumping;

    public:
        const float DiagonalFactor = sqrt(2.0)/2;

	public:
		GameEntity(int,int);

	public:
		bool Load(std::string,SDL_Renderer*);
		void Update();
		void Render(SDL_Renderer*);
		void Destroy();

	public:
		void Move();
    
    private:
        void IncrementalMove(float,float);

	public:
		void HandleCollision();
};

#endif