/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:25:38 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/11 15:55:43 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

/*
**	MANAGE IMG
*/

void	new_graph(t_wolf *wolf)
{
	IMG = mlx_new_image(MLX, WIN_X, WIN_Y);
	ADDR = mlx_get_data_addr(IMG, &BPP, &SLINE, &ENDIAN);
	algo(wolf);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_destroy_image(MLX, IMG);
}

/*
**	BASCI GRAPHICAL FCT
*/

void	start(t_wolf *wolf)
{
	map(wolf);
	initialisation(wolf);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "wolf3d");
	new_graph(wolf);
	mlx_key_hook(WIN, key, wolf);
	mlx_hook(WIN, 17, (1L << 17), echap, wolf);
	mlx_loop(MLX);
}
