#include "Entity.h"

Entity::Entity(SDL_Rect * boundingBox)
{
	this->entityBoundingBox = boundingBox;
    this->hasBeenUpdated = false;
}

bool Entity::CheckCollision(SDL_Rect * boundingBox)
{
	return SdlRectCollision::Collides(this->entityBoundingBox, boundingBox);
}

bool Entity::CheckCollision(Entity * entity)
{
	return SdlRectCollision::Collides(this->entityBoundingBox, entity->entityBoundingBox);
}

SDL_Rect * Entity::GetBoundingBox()
{
	return entityBoundingBox;
}

bool Entity::NeedsUpdate()
{
    return hasBeenUpdated;
}