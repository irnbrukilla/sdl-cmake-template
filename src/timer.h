#ifndef _GAME_TIMER_H_
#define _GAME_TIMER_H_ 1

#include <stdint.h>

typedef struct {
    uint32_t start_ticks;
    uint32_t paused_ticks;
    int paused;
    int started;
} game_timer_t;

game_timer_t* timer_create();
void timer_dispose(game_timer_t* timer);
void timer_start(game_timer_t* timer);
void timer_stop(game_timer_t* timer);
void timer_pause(game_timer_t* timer);
void timer_unpause(game_timer_t* timer);
uint32_t timer_elapsed(game_timer_t* timer);

#endif
