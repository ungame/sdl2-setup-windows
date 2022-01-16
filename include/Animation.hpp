#ifndef ANIMATION_H
#define ANIMATION_H

#include "Asset.hpp"

class Animation
{
    public:
        Animation(Asset* asset, int row, int frames, int speed);
        void animate(SDL_Renderer* renderer, int x, int y, int frameWidth, int frameHeight, float deltaTime);

    private:
        Asset* _asset;
        int _row;
        int _frames;
        int _speed;
        int _currentFrame;
};

#endif