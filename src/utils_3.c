/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:06:39 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/21 10:58:20 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static const char	*parse_sign(const char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

static const char	*parse_integer_part(const char *str, double *result)
{
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10.0 + (*str - '0');
		str++;
	}
	return (str);
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	double	divisor;

	result = 0.0;
	fraction = 0.0;
	divisor = 10.0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	str = parse_sign(str, &sign);
	str = parse_integer_part(str, &result);
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction += (*str - '0') / divisor;
			divisor *= 10.0;
			str++;
		}
	}
	result += fraction;
	return (sign * result);
}

int	get_color(int iteration, int max_iter)
{
	double	t;
	double	curva;
	int		r;
	int		g;
	int		b;

	if (iteration == max_iter)
		return (0x000000);
	t = (double)iteration / max_iter;
	if (max_iter > 500)
		curva = 0.5 + ((double)(max_iter - 100) / 400.0);
	else
		curva = 0.5;
	t = pow(t, curva);
	if (t > 1.0)
		t = 1.0;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	cleanup(t_frac *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}
