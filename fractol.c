/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:55:49 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/01 23:28:25 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (!validate_args(argc, argv))
		return (1);
	f.width = 1200;
	f.height = 800;
	f.max_iter = 35;
	f.zoom = 0.9;
	f.offset_x = 0.0;
	f.offset_y = 0.0;
	f.freeze_iter = 0;
	f.mlx = mlx_init();
	if (!f.mlx)
		return (1);
	f.win = mlx_new_window(f.mlx, f.width, f.height, "fract-ol");
	f.img = mlx_new_image(f.mlx, f.width, f.height);
	f.img_data = mlx_get_data_addr(f.img, &f.bpp, &f.size_line, &f.endian);
	if (!f.win)
		return (1);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		f.fractal_type = 1;
		draw_mandelbrot(&f);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		f.fractal_type = 2;
		draw_julia(&f);
	}
	else if (ft_strcmp(argv[1], "burning") == 0)
	{
		f.fractal_type = 3;
		draw_burning_ship(&f);
	}
	else
	{
		putendl("Fractal not supported.");
		return (1);
	}
	mlx_key_hook(f.win, handle_key, &f);
	mlx_mouse_hook(f.win, handle_mouse, &f);
	mlx_loop(f.mlx);
	return (0);
}
