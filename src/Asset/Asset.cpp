#include "Asset.hpp"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Asset::Asset(SDL_Renderer* renderer, std::string filename) 
{

    SDL_Surface* surface = IMG_Load(filename.c_str());

    if ( surface == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl img load failed: %s", IMG_GetError());
    }

    _texture = SDL_CreateTextureFromSurface(renderer, surface);
    if ( _texture == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create texture from surface failed: %s", IMG_GetError());
    }

}

void Asset::draw(SDL_Renderer* renderer, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)
{
    SDL_Rect src;
    src.x = width * frame;
    src.y = height * row;
    src.w = width;
    src.h = height;

    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = width;
    dst.h = height;

    SDL_RenderCopyEx(renderer, _texture, &src, &dst, 0, nullptr, flip);
}

void Asset::destroy()
{
    SDL_DestroyTexture(_texture);
}
