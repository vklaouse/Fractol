/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 21:50:36 by vklaouse          #+#    #+#             */
/*   Updated: 2016/06/25 20:23:12 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_mandelbrot(t_env *e)
{
	e->c_real = e->x / e->zoom + e->x_1;
	e->c_imag = e->y / e->zoom + e->y_1;
	e->z_real = 0;
	e->z_imag = 0;
	e->i = 0;
	while (e->z_real * e->z_real + e->z_imag * e->z_imag < 4 &&\
		e->i < e->iteration_max)
	{
		e->tmp = e->z_real;
		e->z_real = e->z_real * e->z_real - e->z_imag * e->z_imag + e->c_real;
		e->z_imag = 2 * e->z_imag * e->tmp + e->c_imag;
		e->i++;
	}
	if (e->i == e->iteration_max)
		mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0x000000);
	else
		mlx_pixel_put(e->mlx, e->win, e->x, e->y, e->i * 255);
}

static void	init_mandelbrot(t_env *e)
{
	if (e->key == 0)
	{
		e->x_1 = -2.4;
		e->x_2 = 0.6;
		e->y_1 = -1.7;
		e->y_2 = 1.2;
		e->zoom = 190;
		e->image_x = (e->x_2 - e->x_1) * e->zoom;
		e->image_y = (e->y_2 - e->y_1) * e->zoom;
		e->iteration_max = 50;
		e->zoom /= 1.5;
	}
	e->x = 0;
}

int			mandelbrot(t_env *e)
{
	init_mandelbrot(e);
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			draw_mandelbrot(e);
			e->y++;
		}
		e->x++;
	}
	return (0);
}
