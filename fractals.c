/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:23:38 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/01 18:31:59 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(long double cr, long double ci)
{
	int				i = 0;
	long double		zr = 0;
	long double		zi = 0;
	long double		tmp;

	while ((zr * zr + zi * zi <= 4.0) && i < 100)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	julia(long double zr, long double zi, long double cr, long double ci)
{
	int				i;
	long double		tmp;

	i = 0;
	while ((zr * zr + zi * zi <= 4.0) && i < 100)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	burning_ship(long double cr, long double ci)
{
	int				i = 0;
	long double		zr = 0;
	long double		zi = 0;
	long double		tmp;

	while ((zr * zr + zi * zi <= 4.0) && i < 100)
	{
		tmp = zr;
		zr = fabsl(zr * zr - zi * zi + cr);
		zi = fabsl(2 * tmp * zi + ci);
		i++;
	}
	return (i);
}
