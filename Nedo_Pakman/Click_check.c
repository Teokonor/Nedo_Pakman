#include "Click_check.h"
#include <SDL.h>

int check_clicks(SDL_Event* event, Info* info) {
	SDL_Event ev = *event;
	while (SDL_PollEvent(event) != 0) {
		if (ev.type == SDL_QUIT)
			return 0;
		else if (ev.type == SDL_MOUSEBUTTONDOWN) {
			if ((ev.button.button == SDL_BUTTON_LEFT) & (ev.button.y > 20) & (ev.button.y < 80) & (ev.button.x > 20) & (ev.button.x < 980))
				if (ev.button.x < 80)
					info->clicked_button = 1;
				else if ((ev.button.x > 100) & (ev.button.x < 160))
					info->clicked_button = 2;
				else if ((ev.button.x > 470) & (ev.button.x < 530))
					info->clicked_button = 5;
				else if ((ev.button.x > 840) & (ev.button.x < 900))
					info->clicked_button = 3;
				else if (ev.button.x > 920)
					info->clicked_button = 4;
			if ((ev.button.button == SDL_BUTTON_LEFT) & (ev.button.y > 173) & (ev.button.y < 613) & (ev.button.x > 53) & (ev.button.x < 882))
				if (ev.button.x < 421) {
					if (ev.button.y < 373)
						info->clicked_map = 1;
					else if (ev.button.y > 413)
						info->clicked_map = 2;
				}
				else if (ev.button.x > 514) {
					if (ev.button.y < 373)
						info->clicked_map = 3;
					else if (ev.button.y > 413)
						info->clicked_map = 4;
				}
			if ((ev.button.button == SDL_BUTTON_LEFT) & (ev.button.y > 160) & (ev.button.y < 215) & (ev.button.x > 40) & (ev.button.x < 288))
				info->clicked_theme = 1;
			if ((ev.button.button == SDL_BUTTON_LEFT) & (ev.button.y > 160) & (ev.button.x > 40) & (ev.button.x < 260)) {
				if (ev.button.y < 200)
					info->clicked_difficulty = 1;
				else if (ev.button.y < 240)
					info->clicked_difficulty = 2;
				else if (ev.button.y < 280)
					info->clicked_difficulty = 3;
				else if (ev.button.y < 320)
					info->clicked_difficulty = 4;
			}
				
		}
		else if (ev.type == SDL_KEYDOWN) {
			switch (ev.key.keysym.sym) {
			case SDLK_UP:
				info->keyboard_button = 1;
				break;
			case SDLK_DOWN:
				info->keyboard_button = 2;
				break;
			case SDLK_RIGHT:
				info->keyboard_button = 3;
				break;
			case SDLK_LEFT:
				info->keyboard_button = 4;
				break;
			}
		}
	}
	return 1;
}
