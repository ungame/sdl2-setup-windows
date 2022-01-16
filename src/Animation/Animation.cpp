#include "Animation.hpp"

#include <SDL2/SDL.h>

Animation::Animation(Asset* asset, int row, int frames, int speed)
{
    _asset = asset;
    _row = row;
    _frames = frames;
    _currentFrame = 0;
    _speed = speed;
}

void Animation::animate(SDL_Renderer* renderer, int x, int y, int frameWidth, int frameHeight, float deltaTime)
{
    _currentFrame = (SDL_GetTicks() / _speed) % _frames; 

    _asset->draw(renderer, x, y, frameWidth, frameHeight, _row, _currentFrame);
}