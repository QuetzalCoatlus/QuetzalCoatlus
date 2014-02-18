
#include "SdlRectCollision.h"

SdlRectCollision::SdlRectCollision() {}

bool SdlRectCollision::Collides(SDL_Rect * firstRectangle, SDL_Rect * secondRectangle)
{
	int rectOneLeft = firstRectangle->x;
	int rectOneTop = firstRectangle->y;
	int rectOneRight = firstRectangle->x + firstRectangle->w;
	int rectOneBottom = firstRectangle->y + firstRectangle->h;

	int rectTwoLeft = firstRectangle->x;
	int rectTwoTop = firstRectangle->y;
	int rectTwoRight = firstRectangle->x + firstRectangle->w;
	int rectTwoBottom = firstRectangle->y + firstRectangle->h;

	if(rectOneLeft >= rectTwoRight)
		return false;
	if(rectOneRight <= rectTwoLeft)
		return false;
	if(rectOneTop >= rectTwoBottom)
		return false;
	if(rectOneBottom <= rectTwoTop)
		return false;

	return true;
};
