/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:48:51 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/09 16:34:18 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	algo(t_wolf *wolf)
{
	int	x;

	x = -1;
	while (++x < PROJP_WIDE)
	{
		CAMX = (2 * x) / PROJP_WIDE - 1; // = CAMX = 2 * x / double(PROJP_WIDE) - 1;
		RAY_PX = P_X;
		RAY_PY = P_Y;
		RAY_DX = D_X + PLANX * CAMX;
		RAY_DY = D_Y + PLANY * CAMX;
		//RAY INFO
		MAPX = (int)RAY_PX;
		MAPY = (int)RAY_PY;
		DELTA_DX = sqrt(1 + (RAY_DY * RAY_DY) / (RAY_DX * RAY_DX));
		DELTA_DY = sqrt(1 + (RAY_DX * RAY_DX) / (RAY_DY * RAY_DY));
		HIT = 0;

		if (RAY_DX < 0)
		{
			STEP_X = -1;
			SIDE_DX = (RAY_PX - MAPX) * DELTA_DX;
		}
		else
		{
			STEP_X = 1;
			SIDE_DX = (MAPX + 1 - RAY_PX) * DELTA_DX;
		}
		if (RAY_DY < 0)
		{
			STEP_Y = -1;
			SIDE_DY = (RAY_PY - MAPY) * DELTA_DY;
		}
		else
		{
			STEP_Y = 1;
			SIDE_DY = (MAPY + 1 - RAY_PX) * DELTA_DY;
		}
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
				SIDE_DX += DELTA_DY;
				MAPY += STEP_Y;
				SIDE = 1;
			}
			if (MAP[MAPX][MAPY] > 0)
				HIT = 1;
		}
		printf("MAPX = %d\nMAPY = %d\nSTEP_X = %d\n RAY_DX = %f\n\n====\n", MAPX, MAPY, STEP_X, RAY_DX);
		if (SIDE == 0)
			PERP_WALL_DIST = (MAPX - RAY_PX + (1 - STEP_X) / 2) / RAY_DX;
		else
			PERP_WALL_DIST = (MAPY - RAY_PY + (1 - STEP_Y) / 2) / RAY_DY;
		// !!! PROJP_WIDE DOIT PEU ETRE ETRE REMPLACE PAR PROJP_HIGH !!!
		LINE_H = (int)(PROJP_WIDE * PERP_WALL_DIST); //lineHeight = (int)(h / perpWallDist)
		XI = -LINE_H / 2 + PROJP_WIDE / 2;
		if (XI < 0)
			XI = 0;
		XF = LINE_H / 2 + PROJP_WIDE / 2;
		if (XF >= PROJP_WIDE)
			XF = PROJP_WIDE - 1;
//COLOR WALL
		if (MAP[MAPX][MAPY] == 0)
			COLOR = 0x0000FF;
		else
			COLOR = 0xFF0000;
		if (SIDE == 1)
			COLOR /= 2;
		put_pixel(x, wolf);
	}
}
