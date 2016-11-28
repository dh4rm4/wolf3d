/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:30:52 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 18:00:54 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	initialisation_2(double p_x, double p_xb, double p_y, t_wolf *wolf)
{
	if (NB_MAP == 3)
		TRAP = 0;
	if (TRAP == 0)
		P_X = p_x;
	else
		P_X = p_xb;
	P_Y = p_y;
}

void	initialisation(t_wolf *wolf)
{
	P_X = 18;
	P_Y = 12;
	D_X = -1;
	D_Y = 0;
	PLANX = 0;
	PLANY = 0.66;
	MOVE_SPD = MOVE_SPD_VAL;
	MUSIC = 0;
	TRAP = 0;
}
