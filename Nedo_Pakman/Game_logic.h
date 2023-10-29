#pragma once
#include "Structs.h"
#include "Painting.h"
#include <SDL.h>

void init_erengy(Info* info);

int wall_check(Info* info, int x, int y);

void enemy_move(Info* info, Textures* textures, SDL_Surface* window_surface, int k);

void player_move(Info* info, Textures* textures, SDL_Surface* window_surface);
