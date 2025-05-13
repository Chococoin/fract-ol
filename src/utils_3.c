/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:06:39 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/13 18:07:55 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	return (strtod(str, NULL));
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

int	get_color(int iteration, int max_iter)
{
	double	t;
	double	curva;
	int		r;
	int		g;
	int		b;

	if (iteration == max_iter)
		return (0x000000);
	t = (double)iteration / max_iter;
	if (max_iter > 100)
		curva = 0.5 + ((double)(max_iter - 100) / 400.0);
	else
		curva = 0.5;
	t = pow(t, curva);
	if (t > 1.0)
		t = 1.0;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}
