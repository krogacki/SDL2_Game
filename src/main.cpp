#include <iostream>
#include "Game.h"
#include "testprint.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

	game = new Game();
	game->init("GameWindow", 800, 600, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return EXIT_SUCCESS;
}