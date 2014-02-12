#include <SDL2/SDL.h>

public class Game.h
{
	private:
		SDL_Window * gameWindow;
		SDL_Renderer * gameRenderer;
		SDL_Texture * gameTexture;
		
	private:
		bool isGameRunning;
		
	public:
		Game();
		int ExecuteGame();
		bool InitializeGame();
		bool LoadAssets();
		void RunGameLoop();
		void RunEventLoop();
		void HandleEvents();
		void Update();
		void Render();
		void Cleanup();
};