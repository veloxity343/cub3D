/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:05:57 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/15 14:49:38 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "enum.h"
# include "struct.h"

# define TITLE "cub3D"

# define WIDTH 640
# define HEIGHT 480
# define PIX 64

# define x 0
# define y 1

#endif
