#include "GameEntity.h"

GameEntity::GameEntity(SDL_Rect * boundingBox)
{
	this->entityBoundingBox = boundingBox;
    this->hasBeenUpdated = false;
}