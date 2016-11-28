/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:17:19 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 17:12:46 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int	release_key(int k, t_wolf *wolf)
{
	if (k == 53)
		echap(wolf);
	if (k == MOVE_LEFT)
		CHECK_LEFT = 0;
	else if (k == MOVE_RIGHT)
		CHECK_RIGHT = 0;
	if (k == MOVE_DOWN)
		CHECK_DOWN = 0;
	else if (k == MOVE_UP)
		CHECK_UP = 0;
	if (k == 20)
		map_1(wolf);
	else if (k == 19)
		map_2(wolf);
	else if (k == 18)
		map_3(wolf);
	if (k >= 18 && k <= 21)
		new_graph(wolf);
	return (0);
}
