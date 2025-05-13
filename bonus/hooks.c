/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:24:45 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/13 19:56:17 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_zoom(t_frac *f, int x, int y, long double zoom_factor)
{
	long double	old_zoom;

	old_zoom = f->zoom;
	f->zoom *= zoom_factor;
	f->offset_x += (x - f->w / 2.0) * 4.0L / f->w
		* (1.0L / old_zoom - 1.0L / f->zoom);
	f->offset_y += (y - f->h / 2.0) * 4.0L / f->h
		* (1.0L / old_zoom - 1.0L / f->zoom);
}

static void	update_iterations(t_frac *f)
{
	if (f->zoom <= 1.0)
		f->max_iter = 50;
	else
	{
		f->max_iter = 50 + (int)(log(f->zoom) / (log(1.1)) * 5);
		if (f->max_iter > 500)
			f->max_iter = 500;
	}
}

static void	redraw_fractal(t_frac *f)
{
	if (f->fractal_type == 1)
		draw_mandelbrot(f);
	else if (f->fractal_type == 2)
		draw_julia(f);
	else if (f->fractal_type == 3)
		draw_burning_ship(f);
}

int	handle_mouse(int button, int x, int y, t_frac *f)
{
	long double	zoom_factor;

	if (f->mouse_zoom_cooldown > 0)
	{
		f->mouse_zoom_cooldown--;
		return (0);
	}
	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5)
		zoom_factor = 0.9;
	else
		return (0);
	update_zoom(f, x, y, zoom_factor);
	f->mouse_zoom_cooldown = 3;
	if (!f->freeze_iter)
		update_iterations(f);
	redraw_fractal(f);
	return (0);
}

int	handle_key(int keycode, t_frac *f)
{
	if (keycode == XK_Escape)
		exit(0);
	handle_key_movement(keycode, f);
	handle_key_zoom(keycode, f);
	handle_key_reset(keycode, f);
	if (!f->freeze_iter)
		update_iterations(f);
	redraw_fractal(f);
	return (0);
}
