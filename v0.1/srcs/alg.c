/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:48:51 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/14 17:15:18 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	center(t_wolf *wolf)
{
	int	x;
	int y;
	int	i;

	COLOR = 0x00FF0F;
	x = WIN_X / 2;
	y = -1;//-200;
	while (++y < WIN_Y)
	{
		i = (SLINE * (int)y) + ((int)x * (BPP / 8));
//		i = (SLINE * (int)((PROJP_HIGH + y) / 2)) + ((int)x * (BPP / 8));
		if (ENDIAN == 0)
		{
			ADDR[i] = mlx_get_color_value(MLX, COLOR);
			ADDR[i + 1] = mlx_get_color_value(MLX, COLOR >> 8);
			ADDR[i + 2] = mlx_get_color_value(MLX, COLOR >> 16);
		}
		else
		{
			ADDR[i] = mlx_get_color_value(MLX, COLOR >> 16);
			ADDR[i + 1] = mlx_get_color_value(MLX, COLOR >> 8);
			ADDR[i + 2] = mlx_get_color_value(MLX, COLOR);
		}
	}
	x = -1;
	y = WIN_Y / 2;
	while (++x < WIN_X)
	{
		i = (SLINE * (int)y) + ((int)x * (BPP / 8));
//		i = (SLINE * (int)((PROJP_HIGH + y) / 2)) + ((int)x * (BPP / 8));
		if (ENDIAN == 0)
		{
			ADDR[i] = mlx_get_color_value(MLX, COLOR);
			ADDR[i + 1] = mlx_get_color_value(MLX, COLOR >> 8);
			ADDR[i + 2] = mlx_get_color_value(MLX, COLOR >> 16);
		}
		else
		{
			ADDR[i] = mlx_get_color_value(MLX, COLOR >> 16);
			ADDR[i + 1] = mlx_get_color_value(MLX, COLOR >> 8);
			ADDR[i + 2] = mlx_get_color_value(MLX, COLOR);
		}
	}
}

/*
**	INITIALISE VARIABLES
*/

static void	init(int x, t_wolf *wolf)
{
	CAMX = (2 * x) / (double)(PROJP_WIDE) - 1;
	RAY_PX = P_X;
	RAY_PY = P_Y;
	RAY_DX = D_X + PLANX * CAMX;
	RAY_DY = D_Y + PLANY * CAMX;
	MAPX = (int)(RAY_PX);
	MAPY = (int)(RAY_PY);
	DELTA_DX = sqrt(1 + (RAY_DY * RAY_DY) / (RAY_DX * RAY_DX));
	DELTA_DY = sqrt(1 + (RAY_DX * RAY_DX) / (RAY_DY * RAY_DY));
	HIT = 0;
}

/*
**	FIND THE STEP & DISTANCE
*/

static void	get_dist(t_wolf *wolf)
{
	if (RAY_DX < 0)
	{
		STEP_X = -1;
		SIDE_DX = (RAY_PX - MAPX) * DELTA_DX;
	}
	else
	{
		STEP_X = 1;
		SIDE_DX = (MAPX + 1.0 - RAY_PX) * DELTA_DX;
	}
	if (RAY_DY < 0)
	{
		STEP_Y = -1;
		SIDE_DY = (RAY_PY - MAPY) * DELTA_DY;
	}
	else
	{
		STEP_Y = 1;
		SIDE_DY = (MAPY + 1.0 - RAY_PX) * DELTA_DY;
	}
}

/*
**	FIND THE WALLS
*/

static int	find_wall(t_wolf *wolf)
{
	while (HIT == 0)
	{
		if (SIDE_DX < SIDE_DY)
		{
			SIDE_DX += DELTA_DX;
			MAPX += STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDE_DY += DELTA_DY;
			MAPY += STEP_Y;
			SIDE = 1;
		}
		if (MAPY >= WIN_Y || MAPX >= WIN_X || MAPX < 0 || MAPY < 0)
			return (0);
		if (MAP[MAPX][MAPY] > 0)
			HIT = 1;
	}
//	  ???????? UTILITY ????????
	  if (MAPY >= PROJP_WIDE || MAPX >= PROJP_HIGH || MAPX < 0 || MAPY < 0)
		HIT = 0;
	if (SIDE == 0)
		PWALL_DIST = (MAPX - RAY_PX + (1 - STEP_X) / 2) / RAY_DX;
	else
		PWALL_DIST = (MAPY - RAY_PY + (1 - STEP_Y) / 2) / RAY_DY;
	PWALL_DIST /= 35;
	return (HIT);
}

/*
**	BEFORE DRAWING COLUMN
*/

static void	bef_draw(int x, t_wolf *wolf)
{
//	XI = x;
//	XF = x;
	COLOR = 0xFF0000;
	if (SIDE == 0)
	{
		WALL_X = RAY_PY + PWALL_DIST * RAY_DY;
	}
	else
	{
		COLOR = 0x00FF;
		WALL_X = RAY_PX + PWALL_DIST * RAY_DX;
	}
//	printf("MAPX = %d\nMAPY = %d\n\n", MAPX, MAPY);
	if (MAP[MAPX][MAPY] == 1)
		put_pixel(x, wolf);
	else if (MAP[MAPX][MAPY] == 2)
	{
		COLOR = 0xFFFFFF;
		put_pixel(x, wolf);
	}
//	else
//	{
//		COLOR = 0x0000FF;
//		if (SIDE == 0)
//			COLOR = 0x00FF00;
//		put_pixel(x, wolf);
//	}
//	printf("YI = %d\nYF = %d\n\n", YI, YF);
//	if (YI > 0)
//		put_pixel(x, wolf);
}

void		algo(t_wolf *wolf)
{
	int	x;

	x = -1;
//	printf("MAPX = %d\nMAPY = %d\n", MAPX, MAPY);
	while (++x < PROJP_WIDE)
	{
		init(x, wolf);
		get_dist(wolf);
		find_wall(wolf);
		LINE_H = (int)(PROJP_HIGH * PWALL_DIST);
//			printf("PWALL_DIST = %lf\nLINE_H = %d\n", PWALL_DIST, LINE_H);
		XI = -LINE_H / 2 + PROJP_HIGH / 2;
		if (XI < 0)
			XI = 0;
		XF = LINE_H / 2 + PROJP_HIGH / 2;
		if (XF >= PROJP_HIGH)
			XF = PROJP_HIGH - 1;
//		bef_draw(x, wolf);
		put_pixel(x, wolf);
	}
	center(wolf);
}