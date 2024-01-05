#include "TextureManager.h"
#include "SDL_image.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* ren)
{
  SDL_Surface* tempSurafce = IMG_Load(fileName);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurafce);
  SDL_FreeSurface(tempSurafce);

  return tex;
}
