/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:50:01 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 17:51:08 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

/*
**  FILL 'MAP' WITH 'map_tmp'
*/

void	complete_map(int map_tmp[20][20], t_wolf *wolf)
{
	int	x;
	int	y;

	x = -1;
	while (++x < 20)
	{
		y = -1;
		while (++y < 20)
		{
			MAP[x][y] = map_tmp[x][y];
		}
	}
	if (MUSIC == 1)
	{
		system("killall afplay");
		--MUSIC;
	}
	if (NB_MAP != 3 && TRAP != 1)
		system("afplay ./sounds/win0.mp3");
	music(wolf);
}
