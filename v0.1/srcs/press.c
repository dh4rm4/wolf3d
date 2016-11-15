/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:05:19 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/15 10:47:33 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

/*
**  MANAGE MOVEMENT OF THE PLAYER
*/

int	press(int k, t_wolf *wolf)
{
	if ((k == MOVE_DOWN || k == MOVE_UP) && FOOTSTEPS == 0)
	{
		system("afplay ./sounds/footsteps.mp3 &");
		++FOOTSTEPS;
	}
    if (k == MOVE_LEFT)
	{
		DOLD_X = D_X;
		D_X = D_X * cos(ROT_SPD) - D_Y * sin(ROT_SPD);
		D_Y = DOLD_X * sin(ROT_SPD) + D_Y * cos(ROT_SPD);
		OLD_PLANX = PLANX;
		PLANX = PLANX * cos(ROT_SPD) - PLANY * sin(ROT_SPD);
		PLANY = OLD_PLANX * sin(ROT_SPD) + PLANY * cos(ROT_SPD);
	}
	else if (k == MOVE_RIGHT)
	{
		DOLD_X = D_X;
		D_X = D_X * cos(-ROT_SPD) - D_Y * sin(-ROT_SPD);
		D_Y = DOLD_X * sin(-ROT_SPD) + D_Y * cos(-ROT_SPD);
		OLD_PLANX = PLANX;
		PLANX = PLANX * cos(-ROT_SPD) - PLANY * sin(-ROT_SPD);
		PLANY = OLD_PLANX * sin(-ROT_SPD) + PLANY * cos(-ROT_SPD);
	}
	if (k == MOVE_DOWN)
	{
		if (MAP[(int)(P_X - D_X * MOVE_SPD)][(int)(P_Y)] == 0)
			P_X -= D_X * MOVE_SPD;
		if (MAP[(int)(P_X)][(int)(P_Y - D_Y * MOVE_SPD)] == 0)
			P_Y -= D_Y * MOVE_SPD;
	}
	else if (k == MOVE_UP)
	{
		if (MAP[(int)(P_X + D_X * MOVE_SPD)][(int)(P_Y)] == 0)
			P_X += D_X * MOVE_SPD;
		if (MAP[(int)(P_X)][(int)(P_Y + D_Y * MOVE_SPD)] == 0)
			P_Y += D_Y * MOVE_SPD;
	}
	if (k == 257)
		MOVE_SPD *= 1.7;
	new_graph(wolf);
	return (0);
}
