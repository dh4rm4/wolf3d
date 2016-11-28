/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:05:19 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 17:15:12 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

/*
**  MANAGE MOVEMENT OF THE PLAYER
*/

int	press(int k, t_wolf *wolf)
{
	if (k == MOVE_LEFT)
		CHECK_LEFT = 1;
	else if (k == MOVE_RIGHT)
		CHECK_RIGHT = 1;
	if (k == MOVE_DOWN)
		CHECK_DOWN = 1;
	else if (k == MOVE_UP)
		CHECK_UP = 1;
	if (k == 49 && MUSIC == 0)
		music(wolf);
	else if (k == 49 && MUSIC == 1)
	{
		system("killall afplay");
		MUSIC = 0;
	}
	new_graph(wolf);
	return (0);
}
