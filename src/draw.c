/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:22:19 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/13 18:34:00 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_f(t_frac *f, int (*f_func)(long double, long double, t_frac *))
{
	int				x;
	int				y;
	int				color;
	long double		cr;
	long double		ci;

	reset_image(f);
	y = 0;
	while (y < f->h)
	{
		x = 0;
		while (x < f->w)
		{
			cr = (x - f->w / 2.0) * 4.0L / f->w / f->zoom + f->offset_x;
			ci = (y - f->h / 2.0) * 4.0L / f->h / f->zoom + f->offset_y;
			color = get_color(f_func(cr, ci, f), f->max_iter);
			put_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(f->mlx, f->win);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	put_iteration_info(f);
}

static int	julia_wrapper(long double zr, long double zi, t_frac *f)
{
	return (julia(zr, zi, f->cr, f->ci));
}

int	mandelbrot_wrapper(long double cr, long double ci, t_frac *f)
{
	return (mandelbrot(cr, ci, f));
}

void	draw_julia(t_frac *f)
{
	draw_f(f, julia_wrapper);
}

void	draw_mandelbrot(t_frac *f)
{
	draw_f(f, mandelbrot_wrapper);
}
