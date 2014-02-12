#include <SDL2/SDL.h>

public class Game.h
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
		void HandleEvents();
		void Update();
		void Render();
		void Cleanup();
};