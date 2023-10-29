#include "Structs.h"
#include <SDL.h>


void init_info(Info* info) {
	info->active_difficulty = 1;
	info->active_map = 1;
	info->clicked_button = 0;
	info->clicked_difficulty = 0;
	info->clicked_map = 0;
	info->clicked_theme = 0;
	info->keyboard_button = 0;
	info->status = 0;
	info->theme = 0;
	info->time = 40000;
	info->fuel_time = 30000;
	info->tick = 0;
	info->score = 0;
	info->x = 92;
	info->y = 2;
	info->enemy_energy = 7;
	info->player_energy = 10;
	info->direction = 1;
	for (int i = 0; i < 17; i++)
		info->scores[i] = 0;
	info->scores[11] = 23;
	info->enemy_x[0] = 92; info->enemy_x[1] = 2; info->enemy_x[2] = 183;
	info->enemy_y[0] = 99; info->enemy_y[1] = 50; info->enemy_y[2] = 50;
}

void rewrite_name(Info* info, char name[], int k) {
	if (info->theme == 1) {
		name[k] = 'd'; name[k + 1] = 'a'; name[k + 2] = 'r'; name[k + 3] = 'k';
	}
}

SDL_Surface* optimize_surface(SDL_Surface* window_surface, char* file_name) {
	SDL_Surface* optimized_surface = NULL;
	SDL_Surface* surface = SDL_LoadBMP(file_name);
	optimized_surface = SDL_ConvertSurface(surface, window_surface->format, 0);
	SDL_FreeSurface(surface);
	return optimized_surface;
}

void init_textures(Info* info, Textures* textures, SDL_Surface* window_surface) {
	const int plus = 48;

	char name[8] = "000.bmp\0";
	int k = 0;
	for (int i = 0; i < 41; i++) {
		k = i / 10 + plus;
		name[1] = (char)k;
		k = i % 10 + plus;
		name[2] = (char)k;
		textures->seconds[i] = optimize_surface(window_surface, name);
	}

	char name1[7] = "00.bmp\0";
	for (int i = 0; i < 41; i++) {
		k = i / 10 + plus;
		name1[0] = (char)k;
		k = i % 10 + plus;
		name1[1] = (char)k;
		textures->scores[i] = optimize_surface(window_surface, name1);
	}

	replace_textures_to_lite(info, textures, window_surface);
	textures->field = optimize_surface(window_surface, "map1_lite.bmp");
}

void replace_textures_to_lite(Info* info, Textures* textures, SDL_Surface* window_surface) {
	const int plus = 48;

	for (int i = 0; i < 5; i++)
		if (info->scores[0] / ((i + 1) * 5))
			textures->stars[i] = optimize_surface(window_surface, "star_active_lite.bmp");
		else
			textures->stars[i] = optimize_surface(window_surface, "star_passive_lite.bmp");

	char name1[21] = "difficulty1_lite.bmp\0";
	name1[10] = (char)(info->active_difficulty + plus);
	char name2[7] = "00.bmp\0";
	name2[0] = (char)(info->scores[0] / 10 + plus);
	name2[1] = (char)(info->scores[0] % 10 + plus);
	//SDL_Surface* textures_arr[20] = { textures->button_maps, textures->button_difficulty, textures->button_tools, textures->button_help, textures->button_play,
	//	textures->window_surf, textures->field_point, textures->wall_point, textures->player, textures->enemy, textures->fuel, textures->score, textures->active_star,
	//	textures->passive_star, textures->difficulty, textures->difficulty1, textures->difficulty2, textures->difficulty3, textures->difficulty4, textures->record };
	//char* names_arr[20] = { "button_maps_lite_up.bmp", "button_dissiculty_lite_up.bmp", "button_tools_lite_up.bmp", "button_help_lite_up.bmp", "button_play_lite_up.bmp",
	//	"window_surf_lite.bmp", "field_point_lite.bmp", "wall_point_lite.bmp", "player_lite.bmp", "enemy_lite.bmp", "fuel_lite.bmp", "score_lite.mbp", "active_star_lite.bmp", 
	//	"passive_star_lite.bmp", name1, "difficulty1_lite.bmp", "difficulty2_lite.bmp", "difficulty3_lite.bmp", "difficulty4_lite.bmp", name2};
	//for (int i = 0; i < 20; i++)
	//	*textures_arr[i] = *optimize_surface(window_surface, names_arr[i]);
	textures->button_maps = optimize_surface(window_surface, "button_maps_lite_up.bmp");
	textures->button_difficulty = optimize_surface(window_surface, "button_difficulty_lite_up.bmp");
	textures->button_tools = optimize_surface(window_surface, "button_tools_lite_up.bmp");
	textures->button_help = optimize_surface(window_surface, "button_help_lite_up.bmp");
	textures->button_play = optimize_surface(window_surface, "button_play_lite_up.bmp");
	textures->window_surf = optimize_surface(window_surface, "window_surf_lite.bmp");
	textures->field_point = optimize_surface(window_surface, "field_point_lite.bmp");
	textures->wall_point = optimize_surface(window_surface, "wall_point_lite.bmp");
	textures->player = optimize_surface(window_surface, "player_lite.bmp");
	textures->enemy = optimize_surface(window_surface, "enemy_lite.bmp");
	textures->fuel = optimize_surface(window_surface, "fuel_lite_up.bmp");
	textures->score = optimize_surface(window_surface, "score_lite_up.bmp");
	textures->active_star = optimize_surface(window_surface, "active_star_lite.bmp");
	textures->passive_star = optimize_surface(window_surface, "passive_star_lite.bmp");
	textures->difficulty = optimize_surface(window_surface, name1);
	textures->difficulty1 = optimize_surface(window_surface, "difficulty1_lite.bmp");
	textures->difficulty2 = optimize_surface(window_surface, "difficulty2_lite.bmp");
	textures->difficulty3 = optimize_surface(window_surface, "difficulty3_lite.bmp");
	textures->difficulty4 = optimize_surface(window_surface, "difficulty4_lite.bmp");
	textures->record = optimize_surface(window_surface, name2);
	textures->field = optimize_surface(window_surface, "theme_change_lite.bmp");
}

void replace_textures_to_dark(Info* info, Textures* textures, SDL_Surface* window_surface) {
	const int plus = 48;

	for (int i = 0; i < 5; i++)
		if (info->scores[0] / ((i + 1) * 5))
			textures->stars[i] = optimize_surface(window_surface, "star_active_dark.bmp");
		else
			textures->stars[i] = optimize_surface(window_surface, "star_passive_dark.bmp");

	char name1[21] = "difficulty1_dark.bmp\0";
	name1[10] = (char)(info->active_difficulty + plus);
	char name2[7] = "00.bmp\0";
	name2[0] = (char)(info->scores[0] / 10 + plus);
	name2[1] = (char)(info->scores[0] % 10 + plus);
	
	textures->button_maps = optimize_surface(window_surface, "button_maps_dark_up.bmp");
	textures->button_difficulty = optimize_surface(window_surface, "button_difficulty_dark_up.bmp");
	textures->button_tools = optimize_surface(window_surface, "button_tools_dark_up.bmp");
	textures->button_help = optimize_surface(window_surface, "button_help_dark_up.bmp");
	textures->button_play = optimize_surface(window_surface, "button_play_dark_up.bmp");
	textures->window_surf = optimize_surface(window_surface, "window_surf_dark.bmp");
	textures->field_point = optimize_surface(window_surface, "field_point_dark.bmp");
	textures->wall_point = optimize_surface(window_surface, "wall_point_dark.bmp");
	textures->player = optimize_surface(window_surface, "player_dark.bmp");
	textures->enemy = optimize_surface(window_surface, "enemy_dark.bmp");
	textures->fuel = optimize_surface(window_surface, "fuel_dark_up.bmp");
	textures->score = optimize_surface(window_surface, "score_dark_up.bmp");
	textures->active_star = optimize_surface(window_surface, "active_star_dark.bmp");
	textures->passive_star = optimize_surface(window_surface, "passive_star_dark.bmp");
	textures->difficulty = optimize_surface(window_surface, name1);
	textures->difficulty1 = optimize_surface(window_surface, "difficulty1_dark.bmp");
	textures->difficulty2 = optimize_surface(window_surface, "difficulty2_dark.bmp");
	textures->difficulty3 = optimize_surface(window_surface, "difficulty3_dark.bmp");
	textures->difficulty4 = optimize_surface(window_surface, "difficulty4_dark.bmp");
	textures->record = optimize_surface(window_surface, name2);
	textures->field = optimize_surface(window_surface, "theme_change_dark.bmp");
}

void up_buttons(Info* info, Textures* textures, SDL_Surface* window_surface) {
	char name1[24] = "button_maps_lite_up.bmp\0";
	rewrite_name(info, name1, 12);
	textures->button_maps = optimize_surface(window_surface, name1);
	char name2[30] = "button_difficulty_lite_up.bmp\0";
	rewrite_name(info, name2, 18);
	textures->button_difficulty = optimize_surface(window_surface, name2);
	char name3[25] = "button_tools_lite_up.bmp\0";
	rewrite_name(info, name3, 13);
	textures->button_tools = optimize_surface(window_surface, name3);
	char name4[24] = "button_help_lite_up.bmp\0";
	rewrite_name(info, name4, 12);
	textures->button_help = optimize_surface(window_surface, name4);
	char name5[24] = "button_play_lite_up.bmp\0";
	rewrite_name(info, name5, 12);
	textures->button_play = optimize_surface(window_surface, name5);
}

void update_stars(Info* info, Textures* textures, SDL_Surface* window_surface) {
	if (info->theme == 1) {
		for (int i = 0; i < 5; i++)
			if (info->scores[0] / ((i + 1) * 5))
				textures->stars[i] = optimize_surface(window_surface, "star_active_dark.bmp");
			else
				textures->stars[i] = optimize_surface(window_surface, "star_passive_dark.bmp");
	}
	if (info->theme == 0) {
		for (int i = 0; i < 5; i++)
			if (info->scores[0] / ((i + 1) * 5))
				textures->stars[i] = optimize_surface(window_surface, "star_active_lite.bmp");
			else
				textures->stars[i] = optimize_surface(window_surface, "star_passive_lite.bmp");
	}
}
