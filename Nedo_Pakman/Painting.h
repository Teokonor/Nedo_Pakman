#pragma once
#include "Structs.h"
#include <SDL.h>

void place_surface(SDL_Surface* window_surface, SDL_Surface* surface, int x, int y);

void paint_all(Info* info, Textures* textures, SDL_Surface* window_surface);

void paint_theme(Info* info, Textures* textures, SDL_Surface* window_surface);

void paint_field(Info* info, Textures* textures, SDL_Surface* window_surface, char* name);

void paint_buttons(Info* info, Textures* textures, SDL_Surface* window_surface);

void paint_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface);

void playing_paint(Info* info, Textures* textures, SDL_Surface* window_surface);

void paint_player_or_enemy(Info* info, SDL_Surface* skin, SDL_Surface* window_surface, int x, int y);

void paint_field_element(Info* info, SDL_Surface* skin, SDL_Surface* window_surface, int x[3], int y[3]);
