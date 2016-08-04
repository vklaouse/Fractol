/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 03:57:28 by vklaouse          #+#    #+#             */
/*   Updated: 2016/06/25 20:46:12 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_ship(t_env *e)
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
		e->z_imag = 2 * fabs(e->z_imag) * fabs(e->tmp) + e->c_imag;
		e->i++;
	}
	if (e->i == e->iteration_max)
		mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0x000000);
	else
		mlx_pixel_put(e->mlx, e->win, e->x, e->y, e->i * 10000);
}

static void	init_ship(t_env *e)
{
	if (e->key == 0)
	{
		e->x_1 = -2.1;
		e->x_2 = 0.6;
		e->y_1 = -2.1;
		e->y_2 = 1.2;
		e->zoom = 187;
		e->image_x = (e->x_2 - e->x_1) * e->zoom;
		e->image_y = (e->y_2 - e->y_1) * e->zoom;
		e->iteration_max = 50;
		e->zoom /= 1.5;
	}
	e->x = 0;
}

int			ship(t_env *e)
{
	init_ship(e);
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			draw_ship(e);
			e->y++;
		}
		e->x++;
	}
	return (0);
}
