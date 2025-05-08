/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:05:58 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/08 13:52:08 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(long double cr, long double ci)
{
	int				i;
	long double		zr;
	long double		zi;
	long double		tmp;

	i = 0;
	zr = 0;
	zi = 0;
	while ((zr * zr + zi * zi <= 4.0) && i < 100)
	{
		tmp = zr;
		zr = fabsl(zr * zr - zi * zi + cr);
		zi = fabsl(2 * tmp * zi + ci);
		i++;
	}
	return (i);
}
