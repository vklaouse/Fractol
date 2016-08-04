/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:35:16 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/14 22:15:45 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

/*
** Window size:
*/

# define WINDOW 450

/*
** Key_codes:
*/

# define ESC 53
# define ZOOM 69
# define DEZOOM 78
# define LEFT 123
# define RIGHT 124
# define TOP 126
# define BOT 125
# define REDUCE 75
# define ENLARGE 67
# define RESET 71
# define M 46
# define J 38
# define L 37
# define S 1
# define B 11
# define R 15
# define Y 16

/*
** Mouse_codes:
*/

# define CLIC_R 2
# define CLIC_L 1
# define MOL_UP 5
# define MOL_DOWN 4
# define MOL_R 6
# define MOL_L 7
# define MOTION_NOTIFY 6
# define MOTION_MASK (1L<<6)

/*
** Colors:
*/

# define BLUE 1
# define YELLOW 2
# define RED 3

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	double		image_x;
	double		image_y;
	double		x_1;
	double		x_2;
	double		y_1;
	double		y_2;
	double		zoom;
	double		z_real;
	double		z_imag;
	double		c_real;
	double		c_imag;
	int			x;
	int			y;
	int			i;
	double		tmp;
	int			mandelbrot;
	int			julia;
	int			lapin;
	int			ship;
	char		*str;
	int			iteration_max;
	int			key;
	double		z;
	int			k;
	int			j;
	int			colors;
	int			space;
}				t_env;

int				main(int ac, char **av);
int				mandelbrot(t_env *e);
int				keyboard(int key_code, t_env *env);
int				colors(int i, int colors);
int				julia(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *env);
void			init(t_env *env);
int				lapin(t_env *e);
int				ship(t_env *e);
int				yellow(int i);
int				blue(int i);
int				red(int i);
int				ft_motion(int x, int y, t_env *env);

#endif
