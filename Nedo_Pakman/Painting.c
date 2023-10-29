#include "Painting.h"
#include <SDL.h>
#include <stdio.h>

void place_surface(SDL_Surface* window_surface, SDL_Surface* surface, int x, int y) {
	//SDL_Rect* rectangle = malloc(sizeof(SDL_Rect));
	SDL_Rect rect;// = *rectangle;
	rect.x = x; rect.y = y; rect.w = 1; rect.h = 1;
	SDL_BlitSurface(surface, NULL, window_surface, &rect);
}

void paint_all(Info* info, Textures* textures, SDL_Surface* window_surface) {
	SDL_Surface* textures_arr[16] = { textures->window_surf, textures->button_maps, textures->button_difficulty, textures->button_play,
	textures->button_tools, textures->button_help, textures->seconds[30], textures->scores[0], textures->seconds[40], textures->difficulty, textures->stars[0],
	textures->stars[1], textures->stars[2], textures->stars[3], textures->stars[4], textures->record };
	int x_arr[16] = { 0, 20, 100, 470, 840, 920, 40, 138, 456, 647, 697, 737, 777, 817, 857, 907 };
	int y_arr[16] = { 0, 20, 20, 20, 20, 20, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };
	for (int i = 0; i < 16; i++) {
		place_surface(window_surface, textures_arr[i], x_arr[i], y_arr[i]);
	}
	place_surface(window_surface, textures->field, 35, 155);
}

void paint_theme(Info* info, Textures* textures, SDL_Surface* window_surface) {
	if (info->theme == 0)
		replace_textures_to_lite(info, textures, window_surface);
	else
		replace_textures_to_dark(info, textures, window_surface);
	paint_all(info, textures, window_surface);
}

void paint_field(Info* info, Textures* textures, SDL_Surface* window_surface, char* name) {
	textures->field = optimize_surface(window_surface, name);
	place_surface(window_surface, textures->field, 35, 155);
}

void paint_buttons(Info* info, Textures* textures, SDL_Surface* window_surface) {
	SDL_Surface* textures_arr[5] = { textures->button_maps, textures->button_difficulty, textures->button_play, textures->button_tools, textures->button_help };
	int x_arr[5] = { 20, 100, 470, 840, 920 };
	for (int i = 0; i < 5; i++) {
		place_surface(window_surface, textures_arr[i], x_arr[i], 20);
	}
}

void paint_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface) {
	SDL_Surface* textures_arr[7] = { textures->difficulty, textures->stars[0], textures->stars[1], textures->stars[2], textures->stars[3], textures->stars[4], textures->record };
	int x_arr[7] = { 647, 697, 737, 777, 817, 857, 907 };
	const int y = 100;
	for (int i = 0; i < 7; i++) {
		place_surface(window_surface, textures_arr[i], x_arr[i], y);
	}
}

void playing_paint(Info* info, Textures* textures, SDL_Surface* window_surface) {
	int sec = (info->time + 999) / 1000;
	place_surface(window_surface, textures->seconds[sec], 456, 100);
	sec = (info->fuel_time + 999) / 1000;
	place_surface(window_surface, textures->seconds[sec], 40, 100);
	place_surface(window_surface, textures->scores[info->score], 138, 100);
}

void paint_player_or_enemy(Info* info, SDL_Surface* skin, SDL_Surface* window_surface, int x, int y) {
	x = 40 + x * 5 - 10;
	y = 160 + y * 5 - 10;
	place_surface(window_surface, skin, x, y);
}

void paint_field_element(Info* info, SDL_Surface* skin, SDL_Surface* window_surface, int x[3], int y[3]) {
	for (int i = 0; i < 3; i++) {
		x[i] = 40 + x[i] * 5 - 5;
		y[i] = 160 + y[i] * 5 - 5;
		place_surface(window_surface, skin, x[i], y[i]);
	}
}
