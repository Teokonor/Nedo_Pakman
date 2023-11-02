#include "Structs.h"
#include "Painting.h"
#include "Main_cycle_choose.h"
#include "Click_check.h"
#include <SDL.h>
#include <stdio.h>

int main(int argc, char** argv) {
	SDL_Window* window = NULL;
	SDL_Surface* window_surface = NULL;
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Nedo_Pakman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 700, SDL_WINDOW_SHOWN);
	window_surface = SDL_GetWindowSurface(window);

	Info* info = malloc(sizeof(Info));
	init_info(info);

	Textures* textures = malloc(sizeof(Textures));
	init_textures(info, textures, window_surface);
	
	paint_all(info, textures, window_surface);
	SDL_UpdateWindowSurface(window);
	//SDL_Delay(3000);

	int is_running = 1;
	SDL_Event* ev = malloc(sizeof(SDL_Event));

	int a = 0;
	int finish_time = SDL_GetTicks();
	while (is_running) {
		finish_time += 10;
		is_running = check_clicks(ev, info);
		
		run_main_cycle(info, textures, window_surface);
		SDL_UpdateWindowSurface(window);

		info->clicked_button = 0;
		info->keyboard_button = 0;
		info->clicked_map = 0;
		info->clicked_difficulty = 0;
		info->clicked_theme = 0;

		if (SDL_GetTicks() > finish_time)
			finish_time = SDL_GetTicks();
		else
			while (SDL_GetTicks() < finish_time)
				a = 0;
	}

	SDL_DestroyWindow(window);
	window_surface = NULL; window = NULL;
	SDL_Quit();

	free(info);
	info = NULL;
	return 86;
}




/*
status:
0 - открыто игровое окно, игра не идёт
1 - открыто игровое окно, идёт игра
2 - открыто игровое окно, игра на паузе
10 - открыт список карт
20 - открыт выбор сложности
30 - открыты настройки
40 - открыта справка

clicked_button:
0 - никакая
1 - список карт
2 - выбор сложностей
3 - настройки
4 - помощь
5 - старт/пауза/назад (центральная кнопка)
*/