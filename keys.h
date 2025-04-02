/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <glugo-mu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:03:44 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/04/02 08:28:08 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  include <X11/X.h>
#  include <X11/keysym.h>
#  define MLX_HOOK_KEYPRESS(win, handler, data) \
	mlx_hook(win, KeyPress, KeyPressMask, handler, data)
#  define MLX_HOOK_CLOSE(win, handler, data) \
	mlx_hook(win, DestroyNotify, StructureNotifyMask, handler, data)
# else
#  define XK_Escape 53
#  define XK_Left   123
#  define XK_Right  124
#  define XK_Down   125
#  define XK_Up     126
#  define XK_r      15
#  define XK_R      15
#  define XK_a      0
#  define XK_A      0
#  define XK_z      6
#  define XK_Z      6
#  define XK_f      3
#  define XK_F      3
#  define MLX_HOOK_KEYPRESS(win, handler, data) \
	mlx_key_hook(win, handler, data)
#  define MLX_HOOK_CLOSE(win, handler, data) \
	(void)(win); (void)(handler); (void)(data)
# endif

#endif
