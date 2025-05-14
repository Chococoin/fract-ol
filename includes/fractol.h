/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:04:04 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/14 16:11:01 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <ctype.h>
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
	int			w; // width
	int			h; // height
	int			max_iter;
	int			fractal_type;
	int			freeze_iter;
	long double	zoom;
	long double	offset_x;
	long double	offset_y;
	double		cr;
	double		ci;
}	t_frac;

int		ft_strcmp(char *s1, char *s2);
void	putstr(char *s);
void	putendl(char *s);
int		validate_args(int argc, char **argv);
int		get_color(int iteration, int max_iter);
int		validate_args_bonus(int argc, char **argv);
int		mandelbrot(long double cr, long double ci, t_frac *f);
int		julia(long double zr, long double zi, t_frac *f);
int		burning_ship(long double cr, long double ci, t_frac *f);
int		handle_mouse(int button, int x, int y, t_frac *f);
int		handle_key(int keycode, t_frac *f);
void	draw_mandelbrot(t_frac *f);
void	draw_julia(t_frac *f);
void	draw_burning_ship(t_frac *f);
void	put_pixel(t_frac *f, int x, int y, int color);
void	reset_image(t_frac *f);
void	put_iteration_info(t_frac *f);
void	ft_itoa_to_buf(int n, char *buf);
int		handle_key(int keycode, t_frac *f);
int		exit_hook(t_frac *f);
void	handle_key_reset(int keycode, t_frac *f);
void	handle_key_zoom(int keycode, t_frac *f);
void	handle_key_movement(int keycode, t_frac *f);
double	ft_atof(const char *str);
int		setup_mandelbrot(t_frac *f);
int		setup_julia(t_frac *f, int argc, char **argv);
int		mandelbrot_wrapper(long double cr, long double ci, t_frac *f);
int		setup_burning_ship(t_frac *f);

#endif
