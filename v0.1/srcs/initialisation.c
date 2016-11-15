/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:30:52 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/15 10:43:46 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	initialisation(t_wolf *wolf)
{
	P_X = 18;
	P_Y = 12;
	D_X = -1;
	D_Y = 0;
	PLANX = 0;
	PLANY = 0.66;
	MOVE_SPD = MOVE_SPD_VAL;
	FOOTSTEPS = 0;
}
