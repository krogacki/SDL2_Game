#include <iostream>
#include "Game.h"
#include "testprint.h"

Game *game;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    game = new Game();
    game->init("Simple game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();    
    
    delete game;

    return EXIT_SUCCESS;
}