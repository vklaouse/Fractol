/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:50:23 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/14 17:25:45 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mollette(int button, t_env *env)
{
	if (button == MOL_DOWN)
	{
		if (env->j == 10)
		{
			env->j = 0;
			env->z *= 10;
		}
		env->j++;
		env->zoom /= 1.5;
		if (env->iteration_max > 0)
			env->iteration_max -= 5;
	}
	else if (button == MOL_UP)
	{
		if (env->k == 10)
		{
			env->k = 0;
			env->z /= 10;
		}
		env->k++;
		env->zoom /= 1.5;
		env->zoom /= 0.5;
		if (env->iteration_max < 155)
			env->iteration_max += 5;
	}
}

static void	smile(int button, t_env *env)
{
	if (button == MOL_DOWN || button == MOL_UP)
		mollette(button, env);
	else if (button == CLIC_R)
		env->y_1 /= (1 + env->z);
	else if (button == CLIC_L)
		env->y_1 *= (1 + env->z);
	else if (button == MOL_R)
		env->x_1 *= (1 + env->z);
	else if (button == MOL_L)
		env->x_1 /= (1 + env->z);
}

int			mouse_hook(int button, int x, int y, t_env *env)
{
	env->key++;
	mlx_clear_window(env->mlx, env->win);
	smile(button, env);
	if (env->mandelbrot == 1)
		mandelbrot(env);
	else if (env->julia == 1)
		julia(env);
	else if (env->lapin == 1)
		lapin(env);
	else if (env->ship == 1)
		ship(env);
	return (0);
}
