#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <SDL.h>
#include <SDL_image.h>

#include "common.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int running = 0;

int game_initialize(int screen_width, int screen_height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize: %s\n", SDL_GetError());
        return FALSE;
    }
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    if(window == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    running = TRUE;
    return TRUE;
}

void game_update(uint32_t delta_time)
{
}

void game_render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void game_quit()
{
    running = FALSE;
}

int game_running()
{
    return running;
}

void game_dispose()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}
