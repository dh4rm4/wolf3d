/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:25:38 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 16:35:57 by kboddez          ###   ########.fr       */
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
	initialisation(wolf);
	map(wolf);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_X, WIN_Y, "wolf3d");
	new_graph(wolf);
	mlx_hook(WIN, 17, (1L << 17), echap, wolf);
	mlx_hook(WIN, 2, (1L << 0), press, wolf);
	mlx_hook(WIN, 3, (1L << 1), release_key, wolf);
	mlx_loop_hook(MLX, movement, wolf);
	mlx_loop(MLX);
}
