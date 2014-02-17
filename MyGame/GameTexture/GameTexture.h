#ifndef _GAMETEXTURE_H_
	#define _GAMETEXTURE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

public class GameTexture
{
	private:
		int textureHeight;
		int textureWidth;
		
	private:
		SDL_Texture * gameTexture;
		
	public:
		LTexture();
		
	public:
		bool LoadTextureFromFile(std::string);
		void RenderTexture(int,int,SDL_Renderer*,SDL_Rect*);
		void SetColorModulation(Uint8,Uint8,Uint8);
		void DestroyTexture();
		
	public:
		void SetColor(Uint8,Uint8,Uint8);
		void SetBlendMode(SDL_BlendMode);
		void SetAlpha(Uint8);
		int GetWidth();
		int GetHeight();
};

#endif