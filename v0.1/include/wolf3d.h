/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:12:38 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/08 09:29:08 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
**	INCLUDES
*/
# include "../libft/libft.h"

/*
**	CHANGING VALUES
*/
# define SIZE_WALL 64
# define FOV 60
# define P_HEIGHT 32
# define PROJP_WIDE 320
# define PROJP_HIGH 200
# define PROJ_CTRW 160
# define PROJ_CTRH 100

/*
**	GRAPHICAL MACROS
*/
# define MLX wolf->mlx
# define WIN wolf->win
# define IMG wolf->img
# define ADDR wolf->addr
# define WIN_X wolf->win_x
# define WIN_Y wolf->win_y
# define BPP wolf->bpp
# define ENDIAN wolf->endian

/*
**	MOVMENT MACROS
*/
# define P_X  wolf->plyr.x
# define P_Y  wolf->plyr.y
# define P_ANGLE wolf->plyr.angle
# define D_WALL wolf->dist_wall
# define I_RAY wolf->i_ray
# define I_ANGLE wolf->i_angle

typedef struct  s_complex
{
	double      r;
	double      i;
}               t_complex;

typedef struct	s_pov
{
	double		x;
	double		y;
	double		angle;
}				t_pov;

typedef struct	s_wolf
{
	void        *mlx;
	void        *win;
	void        *img;
	char        *addr;
	int         win_x;
	int         win_y;
	int         bpp;
	int         endian;

	t_pov		plyr;
	double		dist_wall;
	double		i_angle;
	int			i_ray;
}				t_wolf;

typedef struct



#endif
