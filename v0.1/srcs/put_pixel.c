/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:40:53 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/12 14:34:42 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

/*
**	PUT PIXEL IN A COMPLETE COLUMN
*/

void		put_pixel(int x, t_wolf *wolf)
{
	int i;
	int	j;

	j = XI - 1;
//	printf("XI = %d\nXF = %d\n\n", XI, XF);
//	COLOR = 0xFF0000;
//i = (SLINE * (int)((PROJP_HIGH + j) / 2)) + ((int)CAMX * (BPP / 8));
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
