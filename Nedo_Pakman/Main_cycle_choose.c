#include "Main_cycle_choose.h"
#include "Main_cycle.h"



void run_main_cycle(Info* info, Textures* textures, SDL_Surface* window_surface) {
	if (info->clicked_button == 0) { // 0-0, 1-0, 2-0, 10-0, 20-0, 30-0, 40-0
		switch (info->status)
		{
		case 1:
			running_game(info, textures, window_surface);
			break;
		case 10:
			main_cycle_choose_map(info, textures, window_surface);
			break;
		case 20:
			main_cycle_choose_difficulty(info, textures, window_surface);
			break;
		case 30:
			main_cycle_choose_tools(info, textures, window_surface);
			break;
		default:
			break;
		}
	}
	else if ((info->clicked_button == 1) & (info->status != 1) & (info->status != 2) & (info->status != 10)) { // 0-1, 20-1, 30-1, 40-1
		main_cycle_open_maps(info, textures, window_surface);
	}
	else if ((info->clicked_button == 2) & (info->status != 1) & (info->status != 2) & (info->status != 20)) { // 0-2, 10-2, 30-2, 40-2
		main_cycle_open_difficulty(info, textures, window_surface);
	}
	else if ((info->clicked_button == 3) & (info->status != 1) & (info->status != 2) & (info->status != 30)) { // 0-3, 10-3, 20-3, 40-3
		main_cycle_open_tools(info, textures, window_surface);
	}
	else if ((info->clicked_button == 4) & (info->status != 1) & (info->status != 2) & (info->status != 40)) { // 0-4, 10-4, 20-4, 30-4
		main_cycle_open_help(info, textures, window_surface);
	}
	else if (info->clicked_button == 5) { // 0-5, 1-5, 2-5, 10-5, 20-5, 30-5, 40-5
		switch (info->status)
		{
		case 0:
			start_game(info, textures, window_surface);
			break;
		case 1:
			pause_game(info, textures, window_surface);
			break;
		case 2:
			resume_game(info, textures, window_surface);
			break;
		default:
			main_cycle_return_to_0(info, textures, window_surface);
			break;
		}
	}
	else if (((info->status == 1) || (info->status == 2)) & (info->clicked_button != 0) & (info->clicked_button != 5)) { // 1-1, 1-2, 1-3, 1-4, 2-1, 2-2, 2-3, 2-4
		finish_game(info, textures, window_surface);
		switch (info->clicked_button)
		{
		case 1:
			main_cycle_open_maps(info, textures, window_surface);
			break;
		case 2:
			main_cycle_open_difficulty(info, textures, window_surface);
			break;
		case 3:
			main_cycle_open_tools(info, textures, window_surface);
			break;
		case 4:
			main_cycle_open_help(info, textures, window_surface);
			break;
		default:
			break;
		}
	}
	else if (info->status == info->clicked_button * 10) { // 10-1, 20-2, 30-3, 40-4
		main_cycle_return_to_0(info, textures, window_surface);
	}
}