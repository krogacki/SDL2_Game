#include "TextureManager.h"
#include "SDL_image.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
  SDL_Surface* tempSurafce = IMG_Load(fileName);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurafce);
  SDL_FreeSurface(tempSurafce);

  return tex;
}
