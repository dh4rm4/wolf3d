/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:40:53 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 18:09:18 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static void	set_color(t_wolf *wolf)
{
	COLOR = 0xF0FF0F;
	COLOR = (NB_MAP == 2) ? 0x5F0255 : COLOR;
	COLOR = (NB_MAP == 1) ? 0x0F0FFF : COLOR;
	COLOR = (NB_MAP == 0) ? 0x00F0F0 : COLOR;
	COLOR = (TRAP == 1) ? 0x950000 : COLOR;
	if (SIDE == 1 && !TRAP)
		COLOR /= 4;
}

/*
**	PUT PIXEL IN A COMPLETE COLUMN
*/

void		put_pixel(int x, t_wolf *wolf)
{
	int i;
	int	j;

	j = XI - 1;
	set_color(wolf);
	while (++j < XF)
	{
		i = (SLINE * j) + (x * (BPP / 8));
		if (ENDIAN == 0)
		{
			ADDR[i] = mlx_get_color_value(MLX, COLOR);
			ADDR[i + 1] = mlx_get_color_value(MLX, COLOR >> 8);
			ADDR[i + 2] = mlx_get_color_value(MLX, COLOR >> 16);
		}
		else
		{
			ADDR[i] = mlx_get_color_value(MLX, COLOR >> 16);
			ADDR[i + 1] = mlx_get_color_value(MLX, COLOR >> 8);
			ADDR[i + 2] = mlx_get_color_value(MLX, COLOR);
		}
	}
}
