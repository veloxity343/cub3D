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
# define UP				XK_w
# define DOWN			XK_s
# define LEFT			XK_a
# define RIGHT			XK_d
# define L_LEFT			XK_Left
# define L_RIGHT		XK_Right
# define ESC			XK_Escape
# define MOUSE_WRAP		15
# define S_MOVE			0.12
# define S_ROTATE		0.12
# define S_ANIMATE		0.15
# define MM_DIST		8
# define MM_PX			128
# define COL_USR		0x00FF00
# define COL_WALL		0x808080
# define COL_FLOOR		0xE6E6E6
# define COL_SPACE		0x404040

# ifndef O_DIRECTORY
#  define O_DIRECTORY	00200000
# endif

#endif
