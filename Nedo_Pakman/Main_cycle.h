#pragma once
#include "Structs.h"
#include "Painting.h"
#include "Game_logic.h"
#include <string.h>

void start_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // ������ ����

void pause_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // ������������� ����

void resume_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // ���������� ����

void finish_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // ��������� ����

void running_game(Info* info, Textures* textures, SDL_Surface* window_surface);  // ���� ������������

void main_cycle_choose_map(Info* info, Textures* textures, SDL_Surface* window_surface);  // ����� ������� �����

void main_cycle_choose_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface);  // ����� ������� ���������

void main_cycle_choose_tools(Info* info, Textures* textures, SDL_Surface* window_surface);  // ����� �������� ���������

void main_cycle_open_maps(Info* info, Textures* textures, SDL_Surface* window_surface);  // ������� ������ ����

void main_cycle_open_difficulty(Info* info, Textures* textures, SDL_Surface* window_surface);  // ������� ����� ���������

void main_cycle_open_tools(Info* info, Textures* textures, SDL_Surface* window_surface);  // ������� ���������

void main_cycle_open_help(Info* info, Textures* textures, SDL_Surface* window_surface);  // ������� �������

void main_cycle_return_to_0(Info* info, Textures* textures, SDL_Surface* window_surface);  // ���������� ���� �� �������� ���� �� ������� ����

