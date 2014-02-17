#ifndef _GAME_H_
	#define _GAME_H_

#include <SDL.h>
#include <SDL_image.h>

class Game
{
	private:
		SDL_Window * gameWindow;
		SDL_Renderer * gameRenderer;
		SDL_Texture * gameTexture;
		
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
		void RunGameLoop(SDL_Event*);
		void RunEventLoop(SDL_Event*);
		void HandleEvents(SDL_Event*);
			void Quit();
		void Update();
		void Render();
		void Cleanup();


	private:
		bool InitializeSDL();
		bool CreateWindow();
		bool CreateRenderer();
		void IntializeRendererColor();
		bool InitializeImageLoading();
		void ClearScreen();
		void UpdateScreen();
		void DestroyWindow();
		void QuitSdlSubSystems();
};

#endif
