/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 21:21:20 by vklaouse          #+#    #+#             */
/*   Updated: 2016/03/13 07:51:32 by vklaouse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	next_color(int i)
{
	if (i <= 55)
		return (0x337352);
	else if (i <= 60)
		return (0xF1EABE);
	else if (i <= 65)
		return (0x090132);
	else if (i <= 70)
		return (0x04044A);
	else if (i <= 75)
		return (0x000865);
	else if (i <= 80)
		return (0x0B2C89);
	else if (i <= 85)
		return (0x1752B0);
	else if (i <= 90)
		return (0x88B4E3);
	else if (i <= 95)
		return (0xD4EBFB);
	else
		return (0x7AE0F2);
}

static int	color_next(int i)
{
	if (i <= 105)
		return (0xD9C860);
	else if (i <= 110)
		return (0x7AE0F2);
	else if (i <= 115)
		return (0x752859);
	else if (i <= 120)
		return (0xF29CD4);
	else if (i <= 125)
		return (0xA65A8B);
	else if (i <= 130)
		return (0x25591F);
	else if (i <= 135)
		return (0x62A65A);
	else if (i <= 140)
		return (0x78EDF2);
	else if (i <= 145)
		return (0x337073);
	else if (i <= 150)
		return (0xA65A8B);
	else
		return (0x000000);
}

int			blue(int i)
{
	if (i <= 5)
		return (0x000066);
	else if (i <= 10)
		return (0x000099);
	else if (i <= 15)
		return (0x0000CC);
	else if (i <= 20)
		return (0x0000FF);
	else if (i <= 25)
		return (0x3300FF);
	else if (i <= 30)
		return (0x3333FF);
	else if (i <= 35)
		return (0x3366FF);
	else if (i <= 40)
		return (0x3399FF);
	else if (i <= 50)
		return (0x33CCFF);
	else if (i >= 51 && i <= 100)
		return (next_color(i));
	else
		return (color_next(i));
}

int			yellow(int i)
{
	if (i <= 5)
		return (0xFFFF00);
	else if (i <= 10)
		return (0xFFFF33);
	else if (i <= 15)
		return (0xFFFF66);
	else if (i <= 20)
		return (0xFFFF99);
	else if (i <= 25)
		return (0xFFFFCC);
	else if (i <= 30)
		return (0xFFCC99);
	else if (i <= 35)
		return (0xFFCC66);
	else if (i <= 40)
		return (0xFF9966);
	else if (i <= 50)
		return (0xFF9933);
	else if (i >= 51 && i <= 100)
		return (next_color(i));
	else
		return (color_next(i));
}

int			red(int i)
{
	if (i <= 5)
		return (0xFF00000);
	else if (i <= 10)
		return (0xFF0033);
	else if (i <= 15)
		return (0xFF0066);
	else if (i <= 20)
		return (0xFF0099);
	else if (i <= 25)
		return (0xFF00CC);
	else if (i <= 30)
		return (0xFF00FF);
	else if (i <= 35)
		return (0xCC00FF);
	else if (i <= 40)
		return (0xCC00CC);
	else if (i <= 50)
		return (0xCC0099);
	else if (i >= 51 && i <= 100)
		return (next_color(i));
	else
		return (color_next(i));
}
