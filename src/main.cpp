#include <iostream>
#include <SDL2/SDL.h>
#include <testprint.h>

const int WIDTH = 800, HEIGTH = 600;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Hello SDL666 World!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGTH, SDL_WINDOW_ALLOW_HIGHDPI);
    
    KrisLib::print("Witaj! Nieznajomy");

    if (NULL == window)
    {
        std::cout << "Sum Ting Wong : " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;

    while(true)
    {
        if(SDL_PollEvent(&windowEvent))
        {
            if(SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}