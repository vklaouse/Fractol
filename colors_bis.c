/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 07:27:34 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/13 07:49:10 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	colors(int i, int colors)
{
	if (colors == 1)
		return (blue(i));
	else if (colors == 2)
		return (yellow(i));
	else
		return (red(i));
}
