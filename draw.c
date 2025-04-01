/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:22:19 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/01 22:31:34 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *f)
{
	int				x;
	int				y;
	long double		cr;
	long double		ci;
	int				color;

	reset_image(f);
	y = 0;
	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			cr = (x - f->width / 2.0) * 4.0L / f->width / f->zoom + f->offset_x;
			ci = (y - f->height / 2.0) * 4.0L / f->height / f->zoom + f->offset_y;
			color = get_color(mandelbrot(cr, ci), f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(f->mlx, f->win); 
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	draw_julia(t_fractal *f)
{
	int				x;
	int				y;
	long double		zr;
	long double		zi;
	int				color;
	long double		cr;
	long double		ci;

	y = 0;
	cr = -0.7;
	ci = 0.27015;
	reset_image(f);
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			zr = (x - f->width / 2.0) * 4.0L / f->width / f->zoom + f->offset_x;
			zi = (y - f->height / 2.0) * 4.0L / f->height / f->zoom + f->offset_y;
			color = get_color(julia(zr, zi, cr, ci), f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(f->mlx, f->win); 
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	draw_burning_ship(t_fractal *f)
{
	int				x;
	int				y;
	long double		cr, ci;
	int				color;

	reset_image(f);
	y = 0;
	while (y < f->height)
	{
		x = 0;
		while (x < f->width)
		{
			cr = (x - f->width / 2.0) * 4.0L / f->width / f->zoom + f->offset_x;
			ci = (y - f->height / 2.0) * 4.0L / f->height / f->zoom + f->offset_y;
			color = get_color(burning_ship(cr, ci), f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(f->mlx, f->win); 
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}