// =======================================================
// ---------- CI516  Game AI Project 1
// ---------- David Dorrinton, UoB 2022
// =======================================================

#include "Game.h" 
Game* game = nullptr;

//=================================================================================

int main(int argc, char* args[])
{
	const int frameDelay = 1000 / FPS;
	Uint32 frameStartTime;
	int frameTime;

	game = new Game; // create an instance of the game
	// IInitialise SDL 
	game->init("CI516: AI SDL - DD 01", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	game->createGameObjects();

	while (game->running())
	{
		frameStartTime = SDL_GetTicks();

		// Main Game functions
		game->handleEvents();
		game->updateGameObjects();
		game->render();


		// Limit Frame Rate
		frameTime = SDL_GetTicks() - frameStartTime;
		if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
	}

	// Close SDL and clear Memory
	game->clean();

	return 0;
}//=====
//=================================================================================



