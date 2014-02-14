#include <SdlRectCollision.h>

SdlRectCollision::SdlRectCollision() {}

bool SdlRectCollision::Collides(SDL_Rect * firstRectangle, SDL_Rect * secondRectangle)
{
	rectOneLeft = firstRectangle->x;
	rectOneTop = firstRectangle->y;
	rectOneRight = firstRectangle->x + firstRectangle->w;
	rectOneBottom = firstRectangle->y + firstRectangle->h;

	rectTwoLeft = firstRectangle->x;
	rectTwoTop = firstRectangle->y;
	rectTwoRight = firstRectangle->x + firstRectangle->w;
	rectTwoBottom = firstRectangle->y + firstRectangle->h;

	if(rectOneLeft >= rectTwoRight)
		return false;
	if(rectOneRight <= rectTwoLeft)
		return false;
	if(rectOneTop >= RectTwoBottom)
		return false;
	if(rectOneBottom <= rectTwoTop)
		return false;

	return true;
}
