/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:15 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 17:31:39 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WIN_N			"cub3D"
# define WIN_W      	1280
# define WIN_H			720
# define SIZE_TEX		64

# ifdef __linux__
#  define UP			XK_w
#  define DOWN			XK_s
#  define LEFT			XK_a
#  define RIGHT			XK_d
#  define L_LEFT		XK_Left
#  define L_RIGHT		XK_Right
#  define ESC			XK_Escape
# else
#  define UP            13
#  define DOWN          1
#  define LEFT          0
#  define RIGHT         2
#  define L_LEFT        123
#  define L_RIGHT       124
#  define ESC           53
# endif

# ifndef O_DIRECTORY
#  define O_DIRECTORY	00200000
# endif

# ifndef M_PI
#  define M_PI			3.14159265358979323846
# endif

# define S_MOVE			0.12
# define S_ROTATE		0.12
# define FOV_DEGREES	60.0
# define FOV_RADIANS    (FOV_DEGREES * M_PI / 360.0)

#endif
