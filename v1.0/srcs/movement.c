/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:17:48 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 17:51:50 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

/*
**	MANAGE LEFT MOVEMENT
*/

static void	mov_left(t_wolf *wolf)
{
	DOLD_X = D_X;
	D_X = D_X * cos(ROT_SPD) - D_Y * sin(ROT_SPD);
	D_Y = DOLD_X * sin(ROT_SPD) + D_Y * cos(ROT_SPD);
	OLD_PLANX = PLANX;
	PLANX = PLANX * cos(ROT_SPD) - PLANY * sin(ROT_SPD);
	PLANY = OLD_PLANX * sin(ROT_SPD) + PLANY * cos(ROT_SPD);
}

/*
**	MANAGE RIGHT MOVEMENT
*/

static void	mov_right(t_wolf *wolf)
{
	DOLD_X = D_X;
	D_X = D_X * cos(-ROT_SPD) - D_Y * sin(-ROT_SPD);
	D_Y = DOLD_X * sin(-ROT_SPD) + D_Y * cos(-ROT_SPD);
	OLD_PLANX = PLANX;
	PLANX = PLANX * cos(-ROT_SPD) - PLANY * sin(-ROT_SPD);
	PLANY = OLD_PLANX * sin(-ROT_SPD) + PLANY * cos(-ROT_SPD);
}

/*
**	MANAGE UP MOVEMENT
*/

static void	mov_up(t_wolf *wolf)
{
	if (MAP[(int)(P_X + D_X * MOVE_SPD)][(int)(P_Y)] == 0)
		P_X += D_X * MOVE_SPD;
	if (MAP[(int)(P_X)][(int)(P_Y + D_Y * MOVE_SPD)] == 0)
		P_Y += D_Y * MOVE_SPD;
	if (P_X > 2.0 && P_X < 3.65 && P_Y > 7.2 && P_Y < 8.1 && NB_MAP == 3)
		map_2(wolf);
	if ((P_X > 1.2 && P_X < 2.5 && P_Y > 1.45 && P_Y < 2.0 && NB_MAP == 2) ||
		(P_X > 14 && P_X < 15 && D_X > -1 && D_X < 0 && NB_MAP == 2))
	{
		TRAP = 1;
		map_1(wolf);
	}
	if (P_X > 18.0 && P_X < 18.9 && D_X > -1 && D_X < 0.2 && NB_MAP == 2)
		map_1(wolf);
	if (P_X > 1.0 && P_X < 1.3 && D_X > -1 && D_X < 0.2 && NB_MAP == 1)
		map_0(wolf);
}

/*
**	MANAGE DOWN MOVEMENT
*/

static void	mov_down(t_wolf *wolf)
{
	if (MAP[(int)(P_X - D_X * MOVE_SPD)][(int)(P_Y)] == 0)
		P_X -= D_X * MOVE_SPD;
	if (MAP[(int)(P_X)][(int)(P_Y - D_Y * MOVE_SPD)] == 0)
		P_Y -= D_Y * MOVE_SPD;
}

int			movement(t_wolf *wolf)
{
	if (CHECK_LEFT == 1)
		mov_left(wolf);
	else if (CHECK_RIGHT == 1)
		mov_right(wolf);
	if (CHECK_UP == 1)
		mov_up(wolf);
	else if (CHECK_DOWN == 1)
		mov_down(wolf);
	new_graph(wolf);
	return (0);
}
