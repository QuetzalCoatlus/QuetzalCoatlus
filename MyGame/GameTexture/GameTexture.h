#ifndef _GAMETEXTURE_H_
	#define _GAMETEXTURE_H_

#include <string>
#include <SDL.h>
#include <SDL_image.h>

class GameTexture
{
	private:
		int textureHeight;
		int textureWidth;
		
	private:
		SDL_Texture * gameTexture;
		
	public:
		GameTexture();
		
	public:
		bool LoadTextureFromFile(std::string, SDL_Renderer*);
		void RenderTexture(int,int,SDL_Renderer*,SDL_Rect*clippingArea=NULL);
		void SetColorModulation(Uint8,Uint8,Uint8);
		void DestroyTexture();
		
	public:
		void SetColor(Uint8,Uint8,Uint8);
		void SetBlendMode(SDL_BlendMode);
		void SetAlpha(Uint8);
		int GetWidth();
		int GetHeight();

	private:
		void ColorKeyImage(SDL_Surface * surfaceToColorKey);
		Uint32 MapRgbToPixelFormat(SDL_Surface * surfaceWithPixelFormat);
};

#endif