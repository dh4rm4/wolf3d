/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboddez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:12:38 by kboddez           #+#    #+#             */
/*   Updated: 2016/11/15 10:43:31 by kboddez          ###   ########.fr       */
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
# define PROJP_WIDE 1600
# define PROJP_HIGH 1200
# define WIN_X 1600
# define WIN_Y 1200
# define LINE_SIZE 15
# define FRAME 0.025
# define ROT_SPD (3.0 * FRAME)
# define MOVE_SPD_VAL (20.0 * FRAME)
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
# define FOOTSTEPS wolf->footsteps

/*
**	MOVMENT MACROS
*/
# define MAP wolf->map
// ================================
// PLAYER VECTOR
# define P_X  wolf->plyr.x  // = posX REPRESENT THE POSITION OF THE PLAYER
# define P_Y  wolf->plyr.y  // = posY
# define D_X wolf->d_x 	// = dirX REPRESENT THE DIRECTION OF THE PLAYER
# define DOLD_X wolf->dold_x // = oldDirX
# define D_Y wolf->d_y	// = dirY
# define PLANX wolf->planx 	// = planeX CAMERA PLANE OF THE PLAYER
# define OLD_PLANX wolf->old_planx // = oldPlanX
# define PLANY wolf->plany 	// = planeY
// =================================
# define CAMX wolf->camx	// = cameraX POSITION SUR LE PLAN CAM [0-319]
// =================================
// RAY INFO
# define RAY_PX wolf->ray_px // = rayPosX
# define RAY_PY wolf->ray_py // = rayPosY
# define RAY_DX wolf->ray_dx // = rayDireX
# define RAY_DY wolf->ray_dy // = rayDireY
# define MAPX wolf->mapx // = mapX	POSITION ACTUELLE DE RAY DNAS LA MAP
# define MAPY wolf->mapy // = mapY
# define PWALL_DIST wolf->perp_wall_dist // = perpWallDist (PERMET DE CALCULER LA TAILLE DE RAY et DONC LA TAILLE DE LA COLONNE A AFFICHER)
// =================================
// DISTANCE ENTRE CHQUE LIGNE D'INTERSECTION
# define SIDE_DX wolf->side_dx // = sideDistX INTERSECTION WITH Y
# define SIDE_DY wolf->side_dy // = sideDistY INTERSECTION WITH X
# define DELTA_DX wolf->delta_dx // = deltaDistX DISTANCE ENTRE DEUX COLONNES
# define DELTA_DY wolf->delta_dy // = deltaDistY DISTANCE ENTRE DEUX LIGNES
// =================================
# define STEP_X wolf->step_x // = stepX	PERMET DE CONNAITRE LA DIRECTION DE P_X (1 || -1)
# define STEP_Y wolf->step_y // = stepY PERMET DE CONNAITRE LA DIRECTION DE P_Y (1 || -1)
# define HIT wolf->hit //(1 || 0) SI MUR EN FACE DE RAY
# define SIDE wolf->side //DETERMINE SI LE MUR EST PARALLELE (=0) OU PERPENDICULAIRE (=1)
# define LINE_H wolf->line_h // = lineHeight
//DRAW
# define XI wolf->xi // = drawStart
# define XF wolf->xf // = drawEnd
# define TEXT_NUM wolf->text_num // = texNum
# define WALL_X wolf->wall_x // = wallx
# define TEXT_X wolf->text_x // = texX
# define TEXT_Y wolf->text_y // = texY
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
/*
**	MLX VARIABLES
*/
	void        *mlx;
	void        *win;
	void        *img;
	char        *addr;
	int         win_x;
	int         win_y;
	int         bpp;
	int         endian;
	int			sline;

/*
**	PLAYER AND MAP INFOS
*/
	int			map[20][20];
	t_pov		plyr;
	double		dist_wall;
	double		d_x;
	double		dold_x;
	double		d_y;
	double		planx;
	double		old_planx;
	double		plany;
	double		move_spd;
	int			mapx;
	int			mapy;
/*
**	RAY INFOS
*/
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
/*
**	DRAW COLUMN
*/
	int			color;
	int			xi;
	int			xf;
	double		wall_x;
/*
**	SOUNDS
*/
	int			footsteps;
}				t_wolf;

void	start(t_wolf *wolf);
void	new_graph(t_wolf *wolf);
void	initialisation(t_wolf *wolf);

void	map(t_wolf *wolf);
void	map_0(t_wolf *wolf);
void	map_1(t_wolf *wolf);
void	map_2(t_wolf *wolf);
void	map_3(t_wolf *wolf);

void	algo(t_wolf *wolf);
void	put_pixel(int x, t_wolf *wolf);

int		echap(t_wolf *wolf);
int		press(int k, t_wolf *wolf);
int		release_key(int k, t_wolf *wolf);

#endif
