/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:22:19 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/02 07:10:05 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_fractal(t_fractal *f, int (*fractal_func)(long double, long double))
{
	int				x, y, color;
	long double		cr, ci;

	reset_image(f);
	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			cr = (x - f->width / 2.0) * 4.0L / f->width / f->zoom + f->offset_x;
			ci = (y - f->height / 2.0) * 4.0L / f->height / f->zoom + f->offset_y;
			color = get_color(fractal_func(cr, ci), f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(f->mlx, f->win);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	put_iteration_info(f);
}

static int	julia_wrapper(long double zr, long double zi)
{
	return (julia(zr, zi, -0.7, 0.27015));
}

void	draw_mandelbrot(t_fractal *f)
{
	draw_fractal(f, mandelbrot);
}

void	draw_julia(t_fractal *f)
{
	draw_fractal(f, julia_wrapper);
}

void	draw_burning_ship(t_fractal *f)
{
	draw_fractal(f, burning_ship);
}
