/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:17:19 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/15 10:44:31 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int	release_key(int k, t_wolf *wolf)
{
	if (k == MOVE_UP || k == MOVE_DOWN)
	{
		system("killall afplay");
		--FOOTSTEPS;
	}
	if (k == 257)
		MOVE_SPD /= 1.7;
	if (k == 53)
		echap(wolf);
	if (k == 18)
		map_0(wolf);
	else if (k == 19)
		map_1(wolf);
	else if (k == 20)
		map_2(wolf);
	else if (k == 21)
		map_3(wolf);
	if (k >= 18 && k <= 21)
		new_graph(wolf);
	return (0);
}
