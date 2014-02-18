#include "GameEntity.h"

GameEntity::GameEntity(SDL_Rect * boundingBox)
{
	this->entityBoundingBox = boundingBox;
    this->hasBeenUpdated = false;
}

bool GameEntity::CheckCollision(SDL_Rect * boundingBox)
{
	return SdlRectCollision::Collides(this->entityBoundingBox, boundingBox);
}

bool GameEntity::CheckCollision(GameEntity * entity)
{
	return SdlRectCollision::Collides(this->entityBoundingBox, entity->entityBoundingBox);
}

SDL_Rect * GameEntity::GetBoundingBox()
{
	return entityBoundingBox;
}

bool GameEntity::NeedsUpdate()
{
    return hasBeenUpdated;
}