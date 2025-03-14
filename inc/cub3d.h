/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:05:57 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/11 17:23:40 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "enum.h"
# include "struct.h"
# include "prototype.h"

# define TITLE "cub3D"

# define WIDTH 640
# define HEIGHT 480
# define PIX 64

# define X 0
# define Y 1

# define VALID_CHAR_MAP "01NSEW"
# define VALID_PLAYER_POS "NSEW"

# define COLOR_MINIMAP 0x000000
# define COLOR_BORDER_MINIMAP 0xFFFFFF
# define COLOR_PLAYER 0x0000FF

# define MOVE_SPEED 0.05
# define ROTSPEED 0.05

#endif
