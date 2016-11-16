/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:26:06 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 17:14:58 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int	check(int ac, char *av)
{
	if (ac > 1)
	{
		ft_strendl("\033[33;37mwolf3d : illegal option --\n");
		ft_strendl("Wolf3d don't need argument");
		return (-1);
	}
	return (0);
}

int			main(int ac, char *av[])
{
	t_wolf	wolf;

	if (!check(ac, av[1]))
		start(&wolf);
	return (0);
}
