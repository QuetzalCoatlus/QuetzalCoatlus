GameEntity::GameEntity(SDL_Rect * boundingBox)
{
	this->entityBoundingBox = boundingBox;
}

bool GameEntity::CheckCollision(SDL_Rect * boundingBox)
{
	return SdlRectCollision::Collides(this->entityBoundingBox, boundingBox);
}

bool GameEntity::CheckCollision(GameEntity * entity)
{
	return SdlRectCollision::Collides(this->entityBoundingBox, entity->boundingBox);
}

SDL_Rect * GameEntity::GetBoundingBox()
{
	return entityBoundingBox;
}
