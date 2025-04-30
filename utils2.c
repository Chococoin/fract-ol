/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:02:38 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/30 14:42:44 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_image(t_fractal *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->w, f->h);
	f->img_data = mlx_get_data_addr(f->img, &f->bpp, &f->size_line, &f->endian);
}

int	exit_hook(t_fractal *f)
{
	(void)f;
	exit(0);
}

void	setup_hooks(t_fractal *f)
{
	MLX_HOOK_KEYPRESS(f->win, handle_key, f);
	MLX_HOOK_CLOSE(f->win, exit_hook, f);
}

void	put_iteration_info(t_fractal *f)
{
	char	*str;
	char	buffer[50];

	str = "Iterations: ";
	ft_itoa_to_buf(f->max_iter, buffer);
	mlx_string_put(f->mlx, f->win, 10, 10, 0xFFFFFF, str);
	mlx_string_put(f->mlx, f->win, 130, 10, 0xFFFFFF, buffer);
}

void	ft_itoa_to_buf(int n, char *buf)
{
	int		i;
	int		tmp;
	char	tmp_buf[12];
	int		j;

	i = 0;
	tmp = n;
	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return ;
	}
	while (tmp > 0)
	{
		tmp_buf[i++] = '0' + (tmp % 10);
		tmp /= 10;
	}
	j = 0;
	while (j < i)
	{
		buf[j] = tmp_buf[i - j - 1];
		j++;
	}
	buf[i] = '\0';
}
