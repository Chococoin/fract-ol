/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:07:51 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/21 13:06:54 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_fractal(t_frac *f)
{
	f->w = 1200;
	f->h = 800;
	f->max_iter = 75;
	f->zoom = 1.0;
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

static int	select_fractal(t_frac *f, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		return (setup_mandelbrot(f));
	else if (ft_strcmp(argv[1], "julia") == 0)
		return (setup_julia(f, argc, argv));
	else if (ft_strcmp(argv[1], "burning") == 0)
		return (setup_burning_ship(f));
	else
	{
		putendl("Fractal not supported.");
		return (0);
	}
}

static void	setup_hooks(t_frac *f)
{
	mlx_key_hook(f->win, handle_key, f);
	mlx_mouse_hook(f->win, handle_mouse, f);
	mlx_hook_keypress(f->win, handle_key, f);
	mlx_hook_close(f->win, exit_hook, f);
}

int	main(int argc, char **argv)
{
	t_frac	f;

	if (!validate_args_bonus(argc, argv))
		return (1);
	if (!init_fractal(&f))
		return (1);
	if (!select_fractal(&f, argc, argv))
		return (1);
	setup_hooks(&f);
	mlx_loop(f.mlx);
	cleanup(&f);
	return (0);
}
