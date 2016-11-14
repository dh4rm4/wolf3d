/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:03:01 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/14 18:16:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

/*
**	MANAGE MOVEMENT OF THE PLAYER
*/

static void	movement(int k, t_wolf *wolf)
{
	//		printf("%f | %f | %f | %f\n", D_X, D_Y, PLANX, PLANY);
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
	else if (k == MOVE_DOWN)
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
	new_graph(wolf);
}



/*
**	MANAGE KEY HOOK
*/

int	key(int k, t_wolf *wolf)
{
	if (k == 53)
		echap(wolf);
	else if(k >= MOVE_LEFT && k <= MOVE_UP)
		movement(k, wolf);
//	if (k >= MOVE_LEFT && k <= 126)

	return (0);
}
