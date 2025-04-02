/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:23:30 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/01 23:06:27 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* int	get_color(int iteration, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == max_iter)
		return (0x000000);
	t = (double)iteration / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (0x00 << 24 | r << 16 | g << 8 | b);
} */

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
	if (max_iter > 100)
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
