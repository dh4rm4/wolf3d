/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:12:38 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/16 17:58:43 by kboddez          ###   ########.fr       */
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
# define SIZE_TEXT 256
# define FOV 60
# define P_HEIGHT 32
# define PROJP_WIDE 1600
# define PROJP_HIGH 1200
# define WIN_X 1600
# define WIN_Y 1200
# define LINE_SIZE 15
# define FRAME 0.05
# define ROT_SPD (1.5 * FRAME)
# define MOVE_SPD_VAL (2.3 * FRAME)

/*
** INVARIABLE VALUES
*/
# define PI 3.14159
# define PHI 1.61803
# define ECHAP 53
# define MOVE_LEFT 123
# define MOVE_RIGHT 124
# define MOVE_DOWN 125
# define MOVE_UP 126

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
**	SOUNDS MACROS
*/
# define MUSIC wolf->music

/*
**	MOVMENT MACROS
*/
# define MAPX wolf->mapx
# define MAPY wolf->mapy
# define NB_MAP wolf->nb_map
# define MAP wolf->map
# define CHECK_LEFT wolf->check_left
# define CHECK_RIGHT wolf->check_right
# define CHECK_UP wolf->check_up
# define CHECK_DOWN wolf->check_down

/*
**	PLAYER VECTOR
*/
# define TRAP wolf->trap
# define P_X  wolf->plyr.x
# define P_Y  wolf->plyr.y
# define D_X wolf->d_x
# define DOLD_X wolf->dold_x
# define D_Y wolf->d_y
# define PLANX wolf->planx
# define OLD_PLANX wolf->old_planx
# define PLANY wolf->plany
# define CAMX wolf->camx

/*
**	RAYCASTING
*/
# define RAY_PX wolf->ray_px
# define RAY_PY wolf->ray_py
# define RAY_DX wolf->ray_dx
# define RAY_DY wolf->ray_dy
# define PWALL_DIST wolf->perp_wall_dist
# define SIDE_DX wolf->side_dx
# define SIDE_DY wolf->side_dy
# define DELTA_DX wolf->delta_dx
# define DELTA_DY wolf->delta_dy
# define STEP_X wolf->step_x
# define STEP_Y wolf->step_y
# define HIT wolf->hit
# define SIDE wolf->side
# define LINE_H wolf->line_h

/*
**	DRAW
*/
# define XI wolf->xi
# define XF wolf->xf
# define TEXT_NUM wolf->text_num
# define WALL_X wolf->wall_x
# define TEXT_X wolf->text_x
# define TEXT_Y wolf->text_y
# define MOVE_SPD wolf->move_spd

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
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			win_x;
	int			win_y;
	int			bpp;
	int			endian;
	int			sline;

	int			nb_map;
	int			map[20][20];
	int			mapx;
	int			mapy;
	t_pov		plyr;
	double		dist_wall;
	double		d_x;
	double		dold_x;
	double		d_y;
	double		planx;
	double		old_planx;
	double		plany;
	double		move_spd;
	int			trap;

	double		camx;
	double		ray_px;
	double		ray_py;
	double		ray_dx;
	double		ray_dy;
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
	int			check_left;
	int			check_right;
	int			check_up;
	int			check_down;

	int			color;
	int			xi;
	int			xf;
	double		wall_x;

	int			music;
}				t_wolf;

void			start(t_wolf *wolf);
void			new_graph(t_wolf *wolf);
void			initialisation(t_wolf *wolf);
void			initialisation_2(double p_x, double p_xb, double p_y,
								t_wolf *wolf);

void			map(t_wolf *wolf);
void			map_0(t_wolf *wolf);
void			map_1(t_wolf *wolf);
void			map_2(t_wolf *wolf);
void			map_3(t_wolf *wolf);
void			complete_map(int map_tmp[20][20], t_wolf *wolf);

void			algo(t_wolf *wolf);
void			put_pixel(int x, t_wolf *wolf);

int				echap(t_wolf *wolf);
int				press(int k, t_wolf *wolf);
int				release_key(int k, t_wolf *wolf);
int				movement(t_wolf *wolf);
void			music(t_wolf *wolf);

#endif
