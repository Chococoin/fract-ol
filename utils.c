/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:28:07 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/01 22:19:16 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	putstr(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	write(1, s, i);
}

void	putendl(char *s)
{
	putstr(s);
	write(1, "\n", 1);
}

int	validate_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		putendl("Uso: ./fractol mandelbrot | julia");
		return (0);
	}
	return (1);
}

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= f->width || y < 0 || y >= f->height)
		return ;
	dst = f->img_data + (y * f->size_line + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

void	reset_image(t_fractal *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->endian);
}