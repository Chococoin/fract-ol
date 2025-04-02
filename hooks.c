/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:24:45 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/02 08:58:40 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

/* int	handle_key(int keycode, t_fractal *f)
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
} */

void	put_iteration_info(t_fractal *f)
{
	char	*str;
	char	buffer[50];

	str = "Iterations: ";
	ft_itoa_to_buf(f->max_iter, buffer);
	mlx_string_put(f->mlx, f->win, 10, 10, 0xFFFFFF, str);
	mlx_string_put(f->mlx, f->win, 130, 10, 0xFFFFFF, buffer);
}

void	ft_itoa_to_buf(int n, char *buf)
{
	int		i;
	int		tmp;
	char	tmp_buf[12];
	int		j;

	i = 0;
	tmp = n;
	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return;
	}
	while (tmp > 0)
	{
		tmp_buf[i++] = '0' + (tmp % 10);
		tmp /= 10;
	}
	j = 0;
	while (j < i)
	{
		buf[j] = tmp_buf[i - j - 1];
		j++;
	}
	buf[i] = '\0';
}

int	handle_key(int keycode, t_fractal *f)
{
	if (keycode == XK_Escape)
		exit(0);
	else if (keycode == XK_Left)
		f->offset_x -= 0.2 / f->zoom;
	else if (keycode == XK_Right)
		f->offset_x += 0.2 / f->zoom;
	else if (keycode == XK_Up)
		f->offset_y -= 0.2 / f->zoom;
	else if (keycode == XK_Down)
		f->offset_y += 0.2 / f->zoom;
	else if (keycode == XK_r || keycode == XK_R)
	{
		f->zoom = 1.0;
		f->offset_x = 0.0;
		f->offset_y = 0.0;
	}
	else if (keycode == XK_a || keycode == XK_A)
		f->zoom *= 1.1;
	else if (keycode == XK_z || keycode == XK_Z)
		f->zoom *= 0.9;
	else if (keycode == XK_f || keycode == XK_F)
		f->freeze_iter = !f->freeze_iter;
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

int	exit_hook(t_fractal *f)
{
	(void)f;
	exit(0);
}

void	setup_hooks(t_fractal *f)
{
	MLX_HOOK_KEYPRESS(f->win, handle_key, f);
	MLX_HOOK_CLOSE(f->win, exit_hook, f);
}
