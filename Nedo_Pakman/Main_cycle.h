#pragma once
#include "Structs.h"
#include "Painting.h"
#include "Game_logic.h"
#include <string.h>

void start_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // начать игру

void pause_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // приостановить игру

void resume_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // продолжить игру

void finish_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // завершить игру

void running_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // игра продолжается

void main_cycle_choose_map(Info* info, Textures* textures, SDL_Surface* window_surface);  // можно выбрать карту

void main_cycle_choose_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface);  // можно выбрать сложность

void main_cycle_choose_tools(Info* info, Textures* textures, SDL_Surface* window_surface);  // можно изменить настройки

void main_cycle_open_maps(Info* info, Textures* textures, SDL_Surface* window_surface);  // открыть список карт

void main_cycle_open_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface);  // открыть выбор сложности

void main_cycle_open_tools(Info* info, Textures* textures, SDL_Surface* window_surface);  // открыть настройки

void main_cycle_open_help(Info* info, Textures* textures, SDL_Surface* window_surface);  // открыть справку

void main_cycle_return_to_0(Info* info, Textures* textures, SDL_Surface* window_surface);  // возвращает игру из побочных меню на игровое окно

