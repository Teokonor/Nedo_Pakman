#pragma once
#include <SDL.h>
#include <string.h>

typedef struct Info {
	int status,
		active_map,
		active_difficulty,
		theme,
		clicked_button,
		keyboard_button,
		clicked_map,
		clicked_difficulty,
		clicked_theme,
		tick,
		time,
		fuel_time,
		score,
		x,
		y,
		enemy_energy,
		player_energy,
		direction;
	int scores[17];
	int enemy_x[3];
	int enemy_y[3];
} Info;

typedef struct Textures {
	SDL_Surface* button_maps,
		* button_difficulty,
		* button_tools,
		* button_help,
		* button_play,
		* window_surf,
		* field,
		* field_point,
		* wall_point,
		* player,
		* enemy,
		* fuel,
		* score,
		* active_star,
		* passive_star,
		* difficulty,
		* difficulty1,
		* difficulty2,
		* difficulty3,
		* difficulty4,
		* record;
	SDL_Surface* seconds[41];
	SDL_Surface* scores[41];
	SDL_Surface* stars[5];
} Textures;

void init_info(Info* info);

void rewrite_name(Info* info, char name[], int k);

SDL_Surface* optimize_surface(SDL_Surface* window_surface, char* file_name);

void init_textures(Info* info, Textures* textures, SDL_Surface* window_surface);

void replace_textures_to_lite(Info* info, Textures* textures, SDL_Surface* window_surface);

void replace_textures_to_dark(Info* info, Textures* textures, SDL_Surface* window_surface);

void up_buttons(Info* info, Textures* textures, SDL_Surface* window_surface);

void update_stars(Info* info, Textures* textures, SDL_Surface* window_surface);
