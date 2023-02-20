#include <stdio.h>
#include <stdbool.h>

#include "chip8.h"
#include "configuration.h"
#include "SDL2/SDL.h"

bool running = true;

int main(int argc, char **argv) {
    struct chip8 chip8;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        CHIP_8_WINDOW_WIDTH, 
        CHIP_8_WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    }

    SDL_DestroyWindow(window);

    return 0;
}