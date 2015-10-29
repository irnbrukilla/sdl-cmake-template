#include <stdlib.h>
#include <stdint.h>

#include <SDL.h>

#include "timer.h"
#include "common.h"

game_timer_t* timer_create()
{
    game_timer_t* timer = calloc(1, sizeof(game_timer_t));
    timer->start_ticks = 0;
    timer->paused_ticks = 0;
    timer->started = FALSE;
    timer->paused = FALSE;
    return timer;
}

void timer_dispose(game_timer_t* timer)
{
    free(timer);
}

void timer_start(game_timer_t* timer)
{
    timer->started = TRUE;
    timer->paused = FALSE;
    timer->start_ticks = SDL_GetTicks();
}

void timer_stop(game_timer_t* timer)
{
    timer->started = FALSE;
    timer->paused = FALSE;
}

void timer_pause(game_timer_t* timer)
{
    if (timer->started && !timer->paused) {
        timer->paused = TRUE;
        timer->paused_ticks = SDL_GetTicks() - timer->start_ticks;
    }
}

void timer_unpause(game_timer_t* timer)
{
    if (timer->paused) {
        timer->paused = FALSE;
        timer->start_ticks = SDL_GetTicks() - timer->paused_ticks;
        timer->paused_ticks = 0;
    }
}

uint32_t timer_elapsed(game_timer_t* timer)
{
    if (timer->started) {
        if(timer->paused) {
            return timer->paused_ticks;
        } else {
            return SDL_GetTicks() - timer->start_ticks;
        }
    }

    return 0;
}
