/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:54:11 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 16:52:57 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	music(t_wolf *wolf)
{
	if (NB_MAP == 0)
		system("afplay ./sounds/avril_14th.mp3 &");
	else if (NB_MAP == 1 && TRAP != 1)
		system("afplay ./sounds/turok.mp3 &");
	else if (NB_MAP == 1 && TRAP == 1)
	{
		system("afplay ./sounds/first_effect.mp3");
		system("afplay ./sounds/scream.mp3 &");
		system("afplay ./sounds/spooky.mp3 &");
	}
	else if (NB_MAP == 2)
		system("afplay ./sounds/zelda.mp3 &");
	else if (NB_MAP == 3)
		system("afplay ./sounds/codex.mp3 &");
	MUSIC = 1;
}
