/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:55:49 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/13 12:53:50 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_fractal(t_fractal *f)
{
	f->w = 1200;
	f->h = 800;
	f->max_iter = 35;
	f->zoom = 0.9;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->freeze_iter = 0;
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->win = mlx_new_window(f->mlx, f->w, f->h, "fract-ol");
	f->img = mlx_new_image(f->mlx, f->w, f->h);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->endian);
	if (!f->win)
		return (0);
	return (1);
}

static int	select_fractal(t_fractal *f, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		f->fractal_type = 1;
		draw_mandelbrot(f);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
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
	if (!select_fractal(&f, argc, argv))
		return (1);
	setup_hooks(&f);
	mlx_loop(f.mlx);
	return (0);
}
