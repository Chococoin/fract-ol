/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:55:49 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/30 13:58:02 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_fractal(t_fractal *f)
{
	f->width = 1200;
	f->height = 800;
	f->max_iter = 35;
	f->zoom = 0.9;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->freeze_iter = 0;
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->win = mlx_new_window(f->mlx, f->width, f->height, "fract-ol");
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->endian);
	if (!f->win)
		return (0);
	return (1);
}

static int	select_fractal(t_fractal *f, char *arg)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
	{
		f->fractal_type = 1;
		draw_mandelbrot(f);
	}
	else if (ft_strcmp(arg, "julia") == 0)
	{
		f->fractal_type = 2;
		draw_julia(f);
	}
	else if (ft_strcmp(arg, "burning") == 0)
	{
		f->fractal_type = 3;
		draw_burning_ship(f);
	}
	else
	{
		putendl("Fractal not supported.");
		return (0);
	}
	return (1);
}

static void	setup_hooks(t_fractal *f)
{
	mlx_key_hook(f->win, handle_key, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
	MLX_HOOK_KEYPRESS(f->win, handle_key, f);
	MLX_HOOK_CLOSE(f->win, exit_hook, f);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (!validate_args(argc, argv))
		return (1);
	if (!init_fractal(&f))
		return (1);
	if (!select_fractal(&f, argv[1]))
		return (1);
	setup_hooks(&f);
	mlx_loop(f.mlx);
	return (0);
}
