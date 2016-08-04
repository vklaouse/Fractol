/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:43:45 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/14 22:44:03 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int key_code, t_env *env)
{
	if (key_code == ZOOM)
	{
		if (env->k == 10)
		{
			env->k = 0;
			env->z /= 10;
		}
		env->k++;
		env->zoom /= 1.5;
		env->zoom /= 0.5;
	}
	else if (key_code == DEZOOM)
	{
		if (env->j == 10)
		{
			env->j = 0;
			env->z *= 10;
		}
		env->j++;
		env->zoom /= 1.5;
	}
	else if (key_code == RIGHT)
		env->x_1 *= (1 + env->z);
	else if (key_code == LEFT)
		env->x_1 /= (1 + env->z);
}

static void	change(int key_code, t_env *env)
{
	if (key_code == RESET)
	{
		env->z = 0.1;
		env->key = 0;
	}
	else if (key_code == J || key_code == M || key_code == L || key_code == S)
	{
		env->mandelbrot = 0;
		env->julia = 0;
		env->lapin = 0;
		env->ship = 0;
		env->key = 0;
		if (key_code == M)
			env->mandelbrot = 1;
		else if (key_code == L)
			env->lapin = 1;
		else if (key_code == S)
			env->ship = 1;
		else if (key_code == J)
			env->julia = 1;
	}
	else if (key_code == B)
		env->colors = 1;
	else if (key_code == Y)
		env->colors = 2;
}

static void	key(int key_code, t_env *env)
{
	if (key_code == ZOOM || key_code == DEZOOM || key_code == RIGHT || key_code\
		== LEFT)
		zoom(key_code, env);
	else if (key_code == BOT)
		env->y_1 *= (1 + env->z);
	else if (key_code == TOP)
		env->y_1 /= (1 + env->z);
	else if (key_code == ESC)
		exit(0);
	else if (key_code == REDUCE)
	{
		if (env->iteration_max > 0)
			env->iteration_max -= 5;
	}
	else if (key_code == ENLARGE)
	{
		if (env->iteration_max < 155)
			env->iteration_max += 5;
	}
	else if (key_code == RESET || key_code == J || key_code == M ||\
			key_code == L || key_code == S || key_code == B || key_code == Y)
		change(key_code, env);
	else if (key_code == R)
		env->colors = 3;
}

int			keyboard(int key_code, t_env *env)
{
	env->key++;
	mlx_clear_window(env->mlx, env->win);
	key(key_code, env);
	if (key_code == 257)
		env->z /= 10;
	else if (key_code == 258)
		env->z *= 10;
	else if (key_code == 49 && env->space == 0)
		env->space = 1;
	else if (key_code == 49 && env->space == 1)
		env->space = 0;
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
