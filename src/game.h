#ifndef _GAME_H_
#define _GAME_H_ 1

int game_initialize(int screen_width, int screen_height);

void game_update(uint32_t delta_time);

void game_render();

void game_quit();

void game_dispose();

int game_running();

#endif
