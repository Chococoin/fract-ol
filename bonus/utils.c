/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:56:07 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/08 14:51:35 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
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
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	putendl(char *s)
{
	putstr(s);
	write(1, "\n", 1);
}

int	validate_args_bonus(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		putendl("Use: ./fractol mandelbrot | julia | burning");
		return (0);
	}
	return (1);
}

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= f->w || y < 0 || y >= f->h)
		return ;
	dst = f->img_data + (y * f->size_line + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}
