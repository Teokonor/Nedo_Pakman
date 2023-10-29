#include "Game_logic.h"


void write_energy(Info* info, int en, int pl) {
	info->enemy_energy = en;
	info->player_energy = pl;
}

void init_erengy(Info* info) {
	switch (info->active_difficulty)
	{
	case 1:
		write_energy(info, 7, 10);
		break;
	case 2:
		write_energy(info, 5, 7);
		break;
	case 3:
		write_energy(info, 3, 5);
		break;
	case 4:
		write_energy(info, 2, 3);
		break;
	default:
		break;
	}
}

int wall_check(Info* info, int x, int y) {
	int map = info->active_map;
	if (((x == 92) & (y >= 17) & (y <= 84)) || (x == 0) || (x == 185) || (y == 0) || (y == 101))
		return 1;
	else if (map < 4) {
		if ((y == 50) & (x >= 25) & (x <= 160))
			return 1;
		else if (map < 3) {
			if (((x == 46) || (x == 137)) & (((y >= 9) & (y <= 41)) || ((y >= 59) & (y <= 92))))
				return 1;
			else if (map < 2)
				if (((y == 24) || (y == 74)) & (((x >= 13) & (x <= 79)) || ((x >= 105) & (x <= 172))))
					return 1;
		}
	}
	return 0;
}

int can_move(Info* info, int x, int y, int direction) {
	switch (direction)
	{
	case 1:
		y -= 2;
		for (int i = -1; i < 2; i++)
			if (wall_check(info, x + i, y)) return 0;
		break;
	case 2:
		y += 2;
		for (int i = -1; i < 2; i++)
			if (wall_check(info, x + i, y)) return 0;
		break;
	case 3:
		x += 2;
		for (int i = -1; i < 2; i++)
			if (wall_check(info, x, y + i)) return 0;
		break;
	case 4:
		x -= 2;
		for (int i = -1; i < 2; i++)
			if (wall_check(info, x, y + i)) return 0;
		break;
	default:
		break;
	}
	return 1;
}

float mod(float x) {
	if (x < 0)
		return -x;
	else
		return x;
}

void enemy_move(Info* info, Textures* textures, SDL_Surface* window_surface, int k) {
	float xp = (float)info->x, yp = (float)info->y;
	float xe = (float)info->enemy_x[k], ye = (float)info->enemy_y[k];
	float tg = (ye - yp) / (xe - xp);
	float xbase = 1, ybase = 1;
	if (xp < xe) xbase *= -1;
	if (yp < ye) ybase *= -1;
	float x = 0.5 * xbase, y = 0.5 * ybase;
	if ((ye - yp != 0) & (xe - xp != 0)) {
		while (mod(x) < mod(xp - xe)) {
			if (mod(tg * x) <= mod(y))
				x += xbase;
			else
				y += ybase;
			if (wall_check(info, (int)(x + xe - 0.5), (int)(y + ye - 0.5)))
				return;
		}
	}
	if (ye == yp)
		while (mod(x) < mod(xp - xe)) {
			x += xbase;
			if (wall_check(info, (int)(x + xe - 0.5), (int)(y + ye - 0.5)))
				return;
		}
	if (xe == xp)
		while (mod(y) < mod(yp - ye)) {
			y += ybase;
			if (wall_check(info, (int)(x + xe - 0.5), (int)(y + ye - 0.5)))
				return;
		}
	x = 0.5 * xbase; y = 0.5 * ybase;
	int arrx[3];
	int arry[3];
	if ((ye - yp != 0) & (xe - xp != 0)) {
		if (mod(tg * x) <= mod(y)) {
			if (can_move(info, info->enemy_x[k], info->enemy_y[k], (int)(3.5 - xbase / 2))) {
				info->enemy_x[k] += (int)xbase;
				arrx[0] = info->enemy_x[k] - 2 * (int)xbase; arrx[1] = info->enemy_x[k] - 2 * (int)xbase; arrx[2] = info->enemy_x[k] - 2 * (int)xbase;
				arry[0] = info->enemy_y[k] - 1; arry[1] = info->enemy_y[k]; arry[2] = info->enemy_y[k] + 1;
				paint_player_or_enemy(info, textures->enemy, window_surface, info->enemy_x[k], info->enemy_y[k]);
				paint_field_element(info, textures->field_point, window_surface, arrx, arry);
			}
			else if (can_move(info, info->enemy_x[k], info->enemy_y[k], (int)(ybase / 2 + 1.5))) {
				info->enemy_y[k] += (int)ybase;
				arrx[0] = info->enemy_x[k] - 1; arrx[1] = info->enemy_x[k]; arrx[2] = info->enemy_x[k] + 1;
				arry[0] = info->enemy_y[k] - 2 * (int)ybase; arry[1] = info->enemy_y[k] - 2 * (int)ybase; arry[2] = info->enemy_y[k] - 2 * (int)ybase;
				paint_player_or_enemy(info, textures->enemy, window_surface, info->enemy_x[k], info->enemy_y[k]);
				paint_field_element(info, textures->field_point, window_surface, arrx, arry);
			}
		}
		else {
			if (can_move(info, info->enemy_x[k], info->enemy_y[k], (int)(ybase / 2 + 1.5))) {
				info->enemy_y[k] += (int)ybase;
				arrx[0] = info->enemy_x[k] - 1; arrx[1] = info->enemy_x[k]; arrx[2] = info->enemy_x[k] + 1;
				arry[0] = info->enemy_y[k] - 2 * (int)ybase; arry[1] = info->enemy_y[k] - 2 * (int)ybase; arry[2] = info->enemy_y[k] - 2 * (int)ybase;
				paint_player_or_enemy(info, textures->enemy, window_surface, info->enemy_x[k], info->enemy_y[k]);
				paint_field_element(info, textures->field_point, window_surface, arrx, arry);
			}
			else if (can_move(info, info->enemy_x[k], info->enemy_y[k], (int)(3.5 - xbase / 2))) {
				info->enemy_x[k] += (int)xbase;
				arrx[0] = info->enemy_x[k] - 2 * (int)xbase; arrx[1] = info->enemy_x[k] - 2 * (int)xbase; arrx[2] = info->enemy_x[k] - 2 * (int)xbase;
				arry[0] = info->enemy_y[k] - 1; arry[1] = info->enemy_y[k]; arry[2] = info->enemy_y[k] + 1;
				paint_player_or_enemy(info, textures->enemy, window_surface, info->enemy_x[k], info->enemy_y[k]);
				paint_field_element(info, textures->field_point, window_surface, arrx, arry);
			}
		}
	}

	
}


void player_move(Info* info, Textures* textures, SDL_Surface* window_surface) {
	if (can_move(info, info->x, info->y, info->direction) == 0)
		return;
	int arrx[3];
	int arry[3];
	switch (info->direction)
	{
	case 1:
		info->y -= 1;
		arrx[0] = info->x - 1; arrx[1] = info->x; arrx[2] = info->x + 1;
		arry[0] = info->y + 2; arry[1] = info->y + 2; arry[2] = info->y + 2;
		break;
	case 2:
		info->y += 1;
		arrx[0] = info->x - 1; arrx[1] = info->x; arrx[2] = info->x + 1;
		arry[0] = info->y - 2; arry[1] = info->y - 2; arry[2] = info->y - 2;
		break;
	case 3:
		info->x += 1;
		arrx[0] = info->x - 2; arrx[1] = info->x - 2; arrx[2] = info->x - 2;
		arry[0] = info->y - 1; arry[1] = info->y; arry[2] = info->y + 1;
		break;
	case 4:
		info->x -= 1;
		arrx[0] = info->x + 2; arrx[1] = info->x + 2; arrx[2] = info->x + 2;
		arry[0] = info->y - 1; arry[1] = info->y; arry[2] = info->y + 1;
		break;
	default:
		break;
	}
	paint_player_or_enemy(info, textures->player, window_surface, info->x, info->y);
	paint_field_element(info, textures->field_point, window_surface, arrx, arry);
}
