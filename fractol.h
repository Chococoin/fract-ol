/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:04:04 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/02 10:19:07 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "keys.h"
	
typedef struct s_fractal
{
	int			mouse_zoom_cooldown;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	int			max_iter;
	int			fractal_type;
	int			freeze_iter;
	long double	zoom;
	long double	offset_x;
	long double	offset_y;
}	t_fractal;

int		ft_strcmp(char *s1, char *s2);
void	putstr(char *s);
void	putendl(char *s);
int		validate_args(int argc, char **argv);
int		get_color(int iteration, int max_iter);
int		get_color_rainbow(int iteration, int max_iter);
int		mandelbrot(long double cr, long double ci);
int		julia(long double zr, long double zi, long double cr, long double ci);
int		burning_ship(long double cr, long double ci);
int		handle_mouse(int button, int x, int y, t_fractal *f);
int		handle_key(int keycode, t_fractal *f);
void	draw_mandelbrot(t_fractal *f);
void	draw_julia(t_fractal *f);
void	draw_burning_ship(t_fractal *f);
void	put_pixel(t_fractal *f, int x, int y, int color);
void	reset_image(t_fractal *f);
void	put_iteration_info(t_fractal *f);
void	ft_itoa_to_buf(int n, char *buf);
int		handle_key(int keycode, t_fractal *f);
int		exit_hook(t_fractal *f);

#endif
