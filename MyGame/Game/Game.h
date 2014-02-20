#ifndef _GAME_H_
	#define _GAME_H_

#include <SDL.h>
#include <SDL_image.h>
#include "GameEntity.h"
#include "GameFps.h"

class Game
{
	private:
		SDL_Window * gameWindow;
		SDL_Renderer * gameRenderer;
        GameEntity * gameEntity;
		
	private:
		bool gameIsRunning;
		
	private:
		const int WINDOW_WIDTH = 640;
		const int WINDOW_HEIGHT = 480;
		
	public:
		Game();
		int ExecuteGame();
		bool InitializeGame();
		bool LoadAssets();
		void HandleEvents(SDL_Event*);
		void Update();
		void Render();
		void Cleanup();

	public: 
		//---Event Private Functions ---------/
		void Quit();
        void KeyDown(SDL_Keycode);
        void KeyUp(SDL_Keycode);

	private:
		//---Execution Private Functions------/
		void RunGameLoop(SDL_Event*);
		void RunEventLoop(SDL_Event*);
		//---Initialization Private Functions-/
		bool InitializeSDL();
		bool CreateWindow();
		bool CreateRenderer();
		void InitializeRendererColor();
		bool InitializeImageLoading();
		//---Render Private Functions---------/
		void ClearScreen();
        void DisplayTextures();
		void UpdateScreen();
		//---Cleanup Private Functions -------/
		void DestroyWindow();
        void DestroyTextures();
		void QuitSdlSubSystems();
};

#endif
