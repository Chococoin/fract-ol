/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:06:39 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/13 13:25:05 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	return (strtod(str, NULL));
}

int	setup_mandelbrot(t_fractal *f)
{
	f->fractal_type = 1;
	draw_mandelbrot(f);
	return (1);
}

int	setup_julia(t_fractal *f, int argc, char **argv)
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

int	setup_burning_ship(t_fractal *f)
{
	f->fractal_type = 3;
	draw_burning_ship(f);
	return (1);
}
