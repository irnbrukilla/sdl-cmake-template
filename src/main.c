#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "game.h"
#include "timer.h"

game_timer_t* main_timer;
const uint32_t delta_time = 100;
uint32_t accumulator = 0;
uint32_t frame_time = 0;

int main(int argc, char *argv[])
{
    if (!game_initialize(640, 480)) {
        exit(1);
    }
    main_timer = timer_create();

    while(game_running()) {
        frame_time = timer_elapsed(main_timer);
        accumulator += frame_time;

        while(accumulator >= delta_time) {
            game_update(delta_time);
            accumulator -= delta_time;
        }
        game_render();
    }

    // Be a good little dev and return everything to the state it was in before
    // we muddled with it.
    game_dispose();
    timer_dispose(main_timer);
    main_timer = NULL;
    accumulator = 0;
    frame_time = 0;

    return 0;
}
