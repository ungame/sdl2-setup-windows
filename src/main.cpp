#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Asset.hpp"
#include "Animation.hpp"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

#define TARGET_FPS 60
#define TARGET_DELTATIME 1.5f

int main(int argc, char** argv) {

    if ( SDL_Init(SDL_INIT_EVERYTHING) != 0 )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl init everything falhou: %s", SDL_GetError());

        return EXIT_FAILURE;
    }

    // Inicializando imagens com SDL2
    // https://www.libsdl.org/projects/SDL_image/docs/SDL_image.html#SEC8

    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    int imgInitted =  IMG_Init(imgFlags);

    if ( (imgInitted&imgFlags) != imgFlags )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl init jpg,png falhou: %s", IMG_GetError());

        return EXIT_FAILURE;
    }

    SDL_Log("SDL2 funcionando...");

    SDL_Window* window = SDL_CreateWindow("SDL2 2.0.20", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if ( window == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create window falhou: %s", IMG_GetError());

        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); 
    if ( renderer == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create renderer falhou: %s", IMG_GetError());

        return EXIT_FAILURE;
    }

    bool running = true;

    SDL_Rect rect;
    rect.x = WINDOW_WIDTH / 2-25;
    rect.y = WINDOW_HEIGHT / 2;
    rect.w = 50;
    rect.h = 50;

    Asset* player = new Asset(renderer, "assets/player.png");
    int row = 1;
    int frames = 8;
    int speed = 70;
    Animation* playerWalk = new Animation(player, row, frames, speed);

    float lastTime = SDL_GetTicks();
    float deltaTime = 0;
    
    while(running)
    {
        SDL_Event event;

        while ( SDL_PollEvent(&event) )
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            
            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        SDL_RenderFillRect(renderer, &rect);
      
        int frameWidth = 512/8;
        int frameHeight = 512/8;
        int x = WINDOW_WIDTH / 2 - frameWidth / 2;
        int y = rect.y-frameHeight+2;
        playerWalk->animate(renderer, x, y, frameWidth, frameHeight, deltaTime);

        SDL_RenderPresent(renderer);

        deltaTime = (SDL_GetTicks() - lastTime) * (TARGET_FPS / 1000.0f);
        if (deltaTime > TARGET_DELTATIME)
        {
            deltaTime = TARGET_DELTATIME;
        }
        lastTime = SDL_GetTicks();
    }

    free(playerWalk);
    player->destroy();
    free(player);
    
    SDL_DestroyRenderer(renderer);  
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
