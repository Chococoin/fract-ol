/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:24:45 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/01 23:29:22 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

int	handle_mouse(int button, int x, int y, t_fractal *f)
{
	long double	old_zoom;
	long double	zoom_factor;

	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5)
		zoom_factor = 0.9;
	else
		return (0);
	old_zoom = f->zoom;
	f->zoom *= zoom_factor;
	f->offset_x += (x - f->width / 2.0) * 4.0L / f->width * (1.0L / old_zoom - 1.0L / f->zoom);
	f->offset_y += (y - f->height / 2.0) * 4.0L / f->height * (1.0L / old_zoom - 1.0L / f->zoom);
/* 	if (f->zoom < 1.0)
		f->max_iter = 25;
	else
	{
		f->max_iter = 25 + (int)(log(f->zoom) / log(1.1)) * 5;
		if (f->max_iter > 500)
			f->max_iter = 500;
	} */
	if (!f->freeze_iter)
	{
		if (f->zoom <= 1.0)
			f->max_iter = 35;
		else
		{
			f->max_iter = 35 + (int)(log(f->zoom) / log(1.1)) * 5;
			if (f->max_iter > 200)
				f->max_iter = 200;
		}
	}
	if (f->fractal_type == 1)
		draw_mandelbrot(f);
	else if (f->fractal_type == 2)
		draw_julia(f);
	else if (f->fractal_type == 3)
		draw_burning_ship(f);
	return (0);
}

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 3)
	{
		f->freeze_iter = !f->freeze_iter;
		write(1, "F pressed\n", 10);
	}
	if (f->fractal_type == 1)
		draw_mandelbrot(f);
	else if (f->fractal_type == 2)
		draw_julia(f);
	else if (f->fractal_type == 3)
		draw_burning_ship(f);
	return (0);
}
