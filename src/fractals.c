/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:23:38 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/14 14:53:01 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(long double cr, long double ci, t_frac *f)
{
	int				i;
	long double		zr;
	long double		zi;
	long double		tmp;

	i = 0;
	zr = 0;
	zi = 0;
	(void)f;
	while ((zr * zr + zi * zi <= 2.0) && i < f->max_iter)
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
	while ((zr * zr + zi * zi <= 2.0) && i < f->max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	return (i);
}

int	setup_mandelbrot(t_frac *f)
{
	f->fractal_type = 1;
	draw_mandelbrot(f);
	return (1);
}

int	setup_julia(t_frac *f, int argc, char **argv)
{
	f->fractal_type = 2;
	if (argc >= 4)
	{
		f->cr = ft_atof(argv[2]);
		f->ci = ft_atof(argv[3]);
	}
	else
	{
		f->cr = -0.7;
		f->ci = 0.27015;
	}
	draw_julia(f);
	return (1);
}
