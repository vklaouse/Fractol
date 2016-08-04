/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:36:07 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/14 22:15:34 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_motion(int x, int y, t_env *env)
{
	env->key++;
	if (env->space == 0)
	{
		env->c_real = ((double)(x * 2) / env->image_x) - 1;
		env->c_imag = ((double)(y * 2) / env->image_y) - 1;
	}
	julia(env);
	return (0);
}
