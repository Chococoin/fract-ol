/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:03:44 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/05/14 16:10:11 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  include <X11/X.h>
#  include <X11/keysym.h>

static inline void	mlx_hook_keypress(void *win, int (*handler)(), void *data)
{
	mlx_hook(win, KeyRelease, KeyReleaseMask, handler, data);
}

static inline void	mlx_hook_close(void *win, int (*handler)(), void *data)
{
	mlx_hook(win, DestroyNotify, StructureNotifyMask, handler, data);
}

# else

enum
{
	XK_ESCAPE = 53,
	XK_LEFT = 123,
	XK_RIGHT = 124,
	XK_DOWN = 125,
	XK_UP = 126,
	XK_R = 15,
	XK_A = 0,
	XK_Z = 6,
	XK_F = 3
};

static inline void	mlx_hook_keypress(void *win, int (*handler)(), void *data)
{
	mlx_key_hook(win, handler, data);
}

static inline void	mlx_hook_close(void *win, int (*handler)(), void *data)
{
	(void)win;
	(void)handler;
	(void)data;
}

# endif
#endif
