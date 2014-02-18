#include "GameTexture.h"

GameTexture::GameTexture()
{
	textureWidth=0;
	textureHeight=0;
	
	gameTexture=NULL;
}

bool GameTexture::LoadTextureFromFile(std::string filename, SDL_Renderer * gameRenderer)
{
	DestroyTexture();
	
	SDL_Texture * newGameTexture = NULL;
	
	SDL_Surface * surfaceLoadedFromFile = IMG_Load(filename.c_str());
	if(surfaceLoadedFromFile==NULL)
		return false;
	
	ColorKeyImage(surfaceLoadedFromFile);
	
	newGameTexture = 
		SDL_CreateTextureFromSurface(gameRenderer, surfaceLoadedFromFile);
	if(newGameTexture==NULL)
		return false;
	
	textureWidth = surfaceLoadedFromFile->w;
	textureHeight = surfaceLoadedFromFile->h;
	
	SDL_FreeSurface(surfaceLoadedFromFile);
	gameTexture	= newGameTexture;
	
	return gameTexture != NULL;
}

void GameTexture::ColorKeyImage(SDL_Surface * surfaceToColorKey)
{
	Uint32 pixelFormattedColor = MapRgbToPixelFormat(surfaceToColorKey);
	SDL_SetColorKey(surfaceToColorKey, SDL_TRUE, pixelFormattedColor);
}

Uint32 GameTexture::MapRgbToPixelFormat(SDL_Surface * surfaceWithPixelFormat)
{
	return SDL_MapRGB(surfaceWithPixelFormat->format, 0x00, 0xFF, 0xFF);
}

void GameTexture::RenderTexture(int x, int y, SDL_Renderer * gameRenderer, SDL_Rect * clippingArea)
{
	SDL_Rect * renderArea =
				new SDL_Rect{x, y, textureWidth, textureHeight};
	
	if(clippingArea!=NULL)
	{
		renderArea->w=clippingArea->w;
		renderArea->h=clippingArea->h;
	}
	
	SDL_RenderCopy(gameRenderer, gameTexture, clippingArea, renderArea);
}

void GameTexture::DestroyTexture()
{
	if(gameTexture!=NULL)
	{
		SDL_DestroyTexture(gameTexture);
		gameTexture=NULL;
		textureWidth=0;
		textureHeight=0;
	}
}

void GameTexture::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(gameTexture, red, green, blue);
}

void GameTexture::SetBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(gameTexture, blending);
}

void GameTexture::SetAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(gameTexture, alpha);
}

int GameTexture::GetWidth()
{
	return textureWidth;
}

int GameTexture::GetHeight()
{
	return textureHeight;
}

