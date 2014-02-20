#ifndef _ENTITY_H_
	#define _ENTITY_H_

#include <SDL.h>
#include "SdlRectCollision.h"

class Entity
{
	protected:
		float xPosition;
        float yPosition;
    
	public:
		Entity(int,int);
    
};

#endif