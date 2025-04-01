/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:28:07 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/01 18:28:37 by glugo-mu         ###   ########.fr       */
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
