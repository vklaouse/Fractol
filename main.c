/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:30:01 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/14 22:37:14 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WINDOW, WINDOW, env->str);
	if (env->mandelbrot == 1)
		mlx_expose_hook(env->win, mandelbrot, env);
	else if (env->julia == 1)
		mlx_expose_hook(env->win, julia, env);
	else if (env->lapin == 1)
		mlx_expose_hook(env->win, lapin, env);
	else if (env->ship == 1)
		mlx_expose_hook(env->win, ship, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_key_hook(env->win, keyboard, env);
	if (env->julia == 1)
		mlx_hook(env->win, MOTION_NOTIFY, MOTION_MASK, ft_motion, env);
	mlx_loop(env->mlx);
}

static void	init_var(t_env *env)
{
	env->mandelbrot = 0;
	env->julia = 0;
	env->lapin = 0;
	env->ship = 0;
	env->i = 0;
	env->key = 0;
	env->z = 0.1;
	env->k = 0;
	env->j = 0;
	env->colors = 1;
	env->space = 0;
}

static void	parse(t_env *env, char **av)
{
	if (!(env->i = ft_strcmp("Mandelbrot", av[1])))
	{
		env->str = ft_strdup(av[1]);
		env->mandelbrot = 1;
		init(env);
	}
	else if (!(env->i = ft_strcmp("Julia", av[1])))
	{
		env->str = ft_strdup(av[1]);
		env->julia = 1;
		init(env);
	}
	else if (!(env->i = ft_strcmp("Lapin", av[1])))
	{
		env->str = ft_strdup(av[1]);
		env->lapin = 1;
		init(env);
	}
	else if (!(env->i = ft_strcmp("Ship", av[1])))
	{
		env->str = ft_strdup(av[1]);
		env->ship = 1;
		init(env);
	}
}

int			main(int ac, char **av)
{
	t_env env;

	init_var(&env);
	if (ac == 2)
	{
		if (!(env.i = ft_strcmp("Mandelbrot", av[1])) ||\
			!(env.i = ft_strcmp("Julia", av[1])) ||\
			!(env.i = ft_strcmp("Lapin", av[1])) ||\
			!(env.i = ft_strcmp("Ship", av[1])))
			parse(&env, av);
		else
		{
			ft_printf("\033[31mParameter\033[m : ");
			ft_printf("\033[32mJulia || Lapin || Mandelbrot || Ship.\033[m\n");
		}
	}
	else
	{
		ft_printf("\033[31mParameter\033[m : ");
		ft_printf("\033[32mJulia || Lapin || Mandelbrot || Ship.\033[m\n");
	}
	return (0);
}
