/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:12:38 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/09 15:45:52 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
**	INCLUDES
*/
# include "../libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>

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
# define WIN_X 1600
# define WIN_Y 1000

/*
** INVARIABLE VALUES
*/
# define PI 3.14159
# define PHI 1.61803
/*# define AG_60 PROJP_WIDE
# define AG_30 (AG_60 /2)
# define AG_15 (AG_60 / 4)
# define AG_90 (AG_30 * 3)
# define AG_180 (AG_60 * 3)
# define AG_270 (AG_90 * 3)
*/

/*
**	GRAPHICAL MACROS
*/
# define MLX wolf->mlx
# define WIN wolf->win
# define IMG wolf->img
# define ADDR wolf->addr
# define BPP wolf->bpp
# define ENDIAN wolf->endian
# define SLINE wolf->sline
# define COLOR wolf->color

/*
**	MOVMENT MACROS
*/
# define MAP wolf->map
# define P_X  wolf->plyr.x  // = posX
# define P_Y  wolf->plyr.y  // = posY
# define D_X wolf->dirx 	// = dirX
# define D_Y wolf->diry	// = dirY
# define PLANX wolf->planx 	// = planeX
# define PLANY wolf->plany 	// = planeY
# define TIME wolf->time
# define P_TIME wolf->prev_time // = oldTime
# define CAMX wolf->camx	// = cameraX
# define RAY_PX wolf->ray_px // = rayPosX
# define RAY_PY wolf->ray_py // = rayPosY
# define RAY_DX wolf->ray_dx // = rayDireX
# define RAY_DY wolf->ray_dy // = rayDireY
// RAY INFO
# define MAPX wolf->mapx // = mapX
# define MAPY wolf->mapy // = mapY
# define SIDE_DX wolf->side_dx // = sideDistX
# define SIDE_DY wolf->side_dy // = sideDistY
# define DELTA_DX wolf->delta_dx // = deltaDistX
# define DELTA_DY wolf->delta_dy // = deltaDistY
# define PERP_WALL_DIST wolf->perp_wall_dist // = perpWallDist
# define STEP_X wolf->step_x // = stepX
# define STEP_Y wolf->step_y // = stepY
# define HIT wolf->hit
# define SIDE wolf->side
# define LINE_H wolf->line_h // = lineHeight
//DRAW
# define XI wolf->xi // = drawStart
# define XF wolf->xf // = drawEnd
# define TEXT_NUM wolf->text_num // = texNum
# define WALL_X wolf->wall_x // = wallx
# define TEXT_X wolf->text_x // = texX
# define TEXT_Y wolf->text_y // = texY
# define D wolf->d
# define Y wolf->y

typedef struct	s_pov
{
	double		x;
	double		y;
	int			angle;
}				t_pov;

typedef struct	s_complex
{
	double		x;
	double		y;
}				t_complex;

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
	int			sline;
	int			color;

	int			map[15][15];
	t_pov		plyr;
	double		dist_wall;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		time;
	double		prev_time;
	double		camx;
	double		ray_px;
	double		ray_py;
	double		ray_dx;
	double		ray_dy;
//RAY INFO
	int			mapx;
	int			mapy;
	double		side_dx;
	double		side_dy;
	double		delta_dx;
	double		delta_dy;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
//DRAW
	int			xi;
	int			xf;
	int			text_num;
	double		wall_x;
	int			text_x;
	int			text_y;
	int			d;
	int			y;
}				t_wolf;

void	start(t_wolf *wolf);
void	map(t_wolf *wolf);
void	initialisation(t_wolf *wolf);

void	algo(t_wolf *wolf);

int		echap(t_wolf *wolf);
int		key(int k, t_wolf *wolf);

void	put_pixel(int x, t_wolf *wolf);

#endif
