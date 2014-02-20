#include "GameEntity.h"
#include <iostream>

GameEntity::GameEntity(int x, int y) : Entity(x,y)
{
    entityTexture = new GameTexture();
    entityAnimation = new GameAnimation();
    xVelocity = 2.0f;
    yVelocity = 2.0f;
    
    isMovingLeft = false;
    isMovingDown = false;
    isMovingRight = false;
    isMovingUp = false;
}

bool GameEntity::Load(std::string filename, SDL_Renderer *gameRenderer)
{
    entityAnimation->SetMaxFramesInAnimation(6);

	return entityTexture->LoadTextureFromFile(filename, gameRenderer);
}

void GameEntity::Update()
{
    entityAnimation->Animate();
    Move();
}

void GameEntity::Render(SDL_Renderer * gameRenderer)
{
       SDL_Rect clip =
    {
        0,
        entityAnimation->GetCurrentFrame()*73,
        64,
        73
    };
        
    entityTexture->RenderTexture(xPosition,yPosition, gameRenderer,&clip);
}

void GameEntity::Destroy()
{
    entityTexture->DestroyTexture();
}

void GameEntity::Move()
{
    if(isMovingLeft)
        xPosition -= GameFps::FpsControl.GetSpeedFactor() * xVelocity;
    else if(isMovingRight)
        xPosition +=  GameFps::FpsControl.GetSpeedFactor() * xVelocity;
    else if(isMovingUp)
        yPosition -=  GameFps::FpsControl.GetSpeedFactor() * yVelocity;
    else if(isMovingDown)
        yPosition +=  GameFps::FpsControl.GetSpeedFactor() * yVelocity;
}

void GameEntity::HandleCollision()
{

}