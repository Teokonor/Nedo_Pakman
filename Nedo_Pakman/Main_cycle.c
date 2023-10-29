#include "Main_cycle.h"

//void update_button(Info* info, Textures* textures, SDL_Surface* skin, SDL_Surface* window_surface, char name[], int n) {
//	rewrite_name(info, name, n);
//	skin = optimize_surface(window_surface, name);
//	paint_buttons(info, textures, window_surface);
//}

void start_game(Info* info, Textures* textures, SDL_Surface* window_surface) { // начать игру
	place_surface(window_surface, textures->field, 35, 155);
	init_erengy(info);
	info->status = 1;
	char name1[25] = "button_pause_lite_up.bmp\0";
	//update_button(info, textures, textures->button_play, window_surface, name1, 13);
	rewrite_name(info, name1, 13);
	textures->button_play = optimize_surface(window_surface, name1);
	paint_buttons(info, textures, window_surface);
}

void pause_game(Info* info, Textures* textures, SDL_Surface* window_surface) { // приостановить игру
	info->status = 2;
	char name1[26] = "button_play_lite_down.bmp\0";
	rewrite_name(info, name1, 12);
	textures->button_play = optimize_surface(window_surface, name1);
	paint_buttons(info, textures, window_surface);
	//update_button(info, textures, textures->button_play, window_surface, name1, 12);
}

void resume_game(Info* info, Textures* textures, SDL_Surface* window_surface) { // продолжить игру
	info->status = 1;
	char name1[25] = "button_pause_lite_up.bmp\0";
	rewrite_name(info, name1, 13);
	textures->button_play = optimize_surface(window_surface, name1);
	paint_buttons(info, textures, window_surface);
	//update_button(info, textures, window_surface, textures->button_play, name1, 13);
	running_game(info, textures, window_surface);
}

void finish_game(Info* info, Textures* textures, SDL_Surface* window_surface) { // завершить игру
	info->scores[(info->active_map - 1) * 4 + info->active_difficulty] = info->score;
	info->direction = 1; info->fuel_time = 30000; info->status = 0; info->tick = 0; info->time = 40000; info->x = 92; info->y = 2;
	info->enemy_x[0] = 92; info->enemy_x[1] = 2; info->enemy_x[2] = 183;
	info->enemy_y[0] = 99; info->enemy_y[1] = 50; info->enemy_y[2] = 50;
	char name1[24] = "button_play_lite_up.bmp\0";
	rewrite_name(info, name1, 12);
	textures->button_play = optimize_surface(window_surface, name1);
	paint_buttons(info, textures, window_surface);
	//update_button(info, textures, textures->button_play, window_surface, name1, 12);
	paint_difficulty(info, textures, window_surface);
	playing_paint(info, textures, window_surface);
}

void running_game(Info* info, Textures* textures, SDL_Surface* window_surface) { // игра продолжается
	if (info->keyboard_button != 0)
		info->direction = info->keyboard_button;
	info->tick += 1;
	info->time -= 10;
	info->fuel_time -= 10;
	if ((info->time < 0) || (info->fuel_time < 0)) {
		finish_game(info, textures, window_surface);
		return;
	}
	if (info->tick % info->player_energy == 0)
		player_move(info, textures, window_surface);
	for (int i = 0; i < 3; i++) {
		if (info->tick % info->enemy_energy == 0)
			enemy_move(info, textures, window_surface, i);
		if ((abs(info->x - info->enemy_x[i]) < 3) & (abs(info->y - info->enemy_y[i]) < 3)) {
			finish_game(info, textures, window_surface);
			return;
		}
	}
	playing_paint(info, textures, window_surface);
}

void main_cycle_choose_map(Info* info, Textures* textures, SDL_Surface* window_surface) { // можно выбрать карту
	if (info->clicked_map == 0)
		return;
	info->active_map = info->clicked_map;
	info->scores[0] = info->scores[(info->active_map - 1) * 4 + info->active_difficulty];
	main_cycle_return_to_0(info, textures, window_surface);
	char name1[24] = "button_maps_lite_up.bmp\0";
	rewrite_name(info, name1, 12);
	textures->button_maps = optimize_surface(window_surface, name1);
	update_stars(info, textures, window_surface);
	paint_difficulty(info, textures, window_surface);
}

void main_cycle_choose_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface) { // можно выбрать сложность
	const int plus = 48;
	if (info->clicked_difficulty == 0)
		return;
	info->active_difficulty = info->clicked_difficulty;
	info->scores[0] = info->scores[(info->active_map - 1) * 4  + info->active_difficulty];
	/*char namea[21] = "star_active_lite.bmp\0";
	rewrite_name(info, namea, 12);
	char namep[22] = "star_passive_lite.bmp\0";
	rewrite_name(info, namep, 13);
	for (int i = 0; i < 5; i++)
		if (info->scores[0] / ((i + 1) * 5))
			textures->stars[i] = optimize_surface(window_surface, namea);
		else
			textures->stars[i] = optimize_surface(window_surface, namep);*/
	update_stars(info, textures, window_surface);
	char name1[21] = "difficulty1_lite.bmp\0";
	rewrite_name(info, name1, 12);
	name1[10] = (char)(info->active_difficulty + plus);
	textures->difficulty = optimize_surface(window_surface, name1);
	paint_difficulty(info, textures, window_surface);
}

void main_cycle_choose_tools(Info* info, Textures* textures, SDL_Surface* window_surface) { // можно изменить настройки
	if (info->clicked_theme == 1){
		info->theme = 1 - info->theme;
		paint_theme(info, textures, window_surface);
	}
}

void main_cycle_open_maps(Info* info, Textures* textures, SDL_Surface* window_surface) { // открыть список карт
	char name[20] = "map_change_lite.bmp\0";
	rewrite_name(info, name, 11);
	paint_field(info, textures, window_surface, name);
	info->status = 10;
	char name1[26] = "button_maps_lite_down.bmp\0";
	rewrite_name(info, name1, 12);
	textures->button_maps = optimize_surface(window_surface, name1);
	paint_buttons(info, textures, window_surface);
	//update_button(info, textures, textures->button_maps, window_surface, name1, 12);
}

void main_cycle_open_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface) { // открыть выбор сложности
	char name[27] = "difficulty_change_lite.bmp\0";
	rewrite_name(info, name, 18);
	paint_field(info, textures, window_surface, name);
	info->status = 20;
	char name2[32] = "button_difficulty_lite_down.bmp\0";
	rewrite_name(info, name2, 18);
	textures->button_difficulty = optimize_surface(window_surface, name2);
	paint_buttons(info, textures, window_surface);
	//update_button(info, textures, textures->button_difficulty, window_surface, name2, 18);
}

void main_cycle_open_tools(Info* info, Textures* textures, SDL_Surface* window_surface) { // открыть настройки
	char name[22] = "theme_change_lite.bmp\0";
	rewrite_name(info, name, 13);
	paint_field(info, textures, window_surface, name);
	info->status = 30;
	char name3[27] = "button_tools_lite_down.bmp\0";
	rewrite_name(info, name3, 13);
	textures->button_tools = optimize_surface(window_surface, name3);
	paint_buttons(info, textures, window_surface);
	//update_button(info, textures, textures->button_tools, window_surface, name3, 13);
}

void main_cycle_open_help(Info* info, Textures* textures, SDL_Surface* window_surface) { // открыть справку
	char name[14] = "help_lite.bmp\0";
	rewrite_name(info, name, 5);
	paint_field(info, textures, window_surface, name);
	info->status = 40;
	char name3[26] = "button_help_lite_down.bmp\0";
	rewrite_name(info, name3, 12);
	textures->button_help = optimize_surface(window_surface, name3);
	paint_buttons(info, textures, window_surface);
	//update_button(info, textures, textures->button_help, window_surface, name3, 12);
}

void main_cycle_return_to_0(Info* info, Textures* textures, SDL_Surface* window_surface) { // возвращает игру из побочных меню на игровое окно
	const int plus = 48;
	char name[14] = "map1_lite.bmp\0";
	rewrite_name(info, name, 5);
	name[3] = (char)(info->active_map + plus);
	paint_field(info, textures, window_surface, name);
	info->status = 0;
	up_buttons(info, textures, window_surface);
	paint_buttons(info, textures, window_surface);
}


