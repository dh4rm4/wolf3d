/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:06:39 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/14 18:35:48 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

//CHANGE WIN_X PAR WINY et INVERSEMNET

static void	init(int x, t_wolf *wolf)
{
	CAMX = 2 * x / (double)WIN_X - 1;
	RAY_PX = P_X;
	RAY_PY = P_Y;
	RAY_DX = D_X + PLANX * CAMX;
	RAY_DY = D_Y + PLANY * CAMX;
	MAPX = (int)RAY_PX;
	MAPY = (int)RAY_PY;
	DELTA_DX = sqrt(1 + (RAY_DY * RAY_DY) / (RAY_DX * RAY_DX));
	DELTA_DY = sqrt(1 + (RAY_DX * RAY_DX) / (RAY_DY * RAY_DY));
	HIT = 0;
}

static void	calc_dist(t_wolf *wolf)
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
		SIDE_DY = (MAPY + 1.0 - RAY_PY) * DELTA_DY;
	}
}

static void	find_wall(t_wolf *wolf)
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
		if (MAP[MAPX][MAPY] > 0)
			HIT = 1;
	}
}

void		algo(t_wolf *wolf)
{
	int	x;

	x = -1;
	while (++x < WIN_X)
	{
		init(x, wolf);
		calc_dist(wolf);
		find_wall(wolf);
		if (SIDE == 0)
			PWALL_DIST = (MAPX - RAY_PX + (1 - STEP_X) / 2) / RAY_DX;
		else
			PWALL_DIST = (MAPY - RAY_PY + (1 - STEP_Y) / 2) / RAY_DY;
		LINE_H = (int)(WIN_Y / PWALL_DIST);
		XI = -LINE_H / 2 + WIN_Y / 2;
		if (XI < 0)
			XI = 0;
		XF = LINE_H / 2 + WIN_Y / 2;
		if (XF >= WIN_Y)
			XF = WIN_Y - 1;
		COLOR = 0x00FF00;
		if (SIDE == 1)
			COLOR /= 4;
		put_pixel(x, wolf);
	}
}
