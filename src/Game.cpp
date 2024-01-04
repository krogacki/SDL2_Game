#include "Game.h"
#include <iostream>

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (true == fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (0 == SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cout << "Subsystem Initialized!" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (NULL != window) {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            std::cout << "Renderer created!" << std::endl;
        }
        
        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Game::update()
{
    
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //put stuff to render
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

bool Game::running()
{
    return isRunning;
}
