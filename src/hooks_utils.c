/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:52 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/13 18:11:47 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_key_movement(int keycode, t_frac *f)
{
	if (keycode == XK_Left)
		f->offset_x -= 0.2 / f->zoom;
	else if (keycode == XK_Right)
		f->offset_x += 0.2 / f->zoom;
	else if (keycode == XK_Up)
		f->offset_y -= 0.2 / f->zoom;
	else if (keycode == XK_Down)
		f->offset_y += 0.2 / f->zoom;
}

void	handle_key_zoom(int keycode, t_frac *f)
{
	if (keycode == XK_a || keycode == XK_A)
		f->zoom *= 1.1;
	else if (keycode == XK_z || keycode == XK_Z)
		f->zoom *= 0.9;
}

void	handle_key_reset(int keycode, t_frac *f)
{
	if (keycode == XK_r || keycode == XK_R)
	{
		f->zoom = 1.0;
		f->offset_x = 0.0;
		f->offset_y = 0.0;
	}
	else if (keycode == XK_f || keycode == XK_F)
	{
		f->freeze_iter = !f->freeze_iter;
		write(1, "F pressed\n", 10);
	}
}
