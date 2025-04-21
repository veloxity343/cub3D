/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:16:06 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 10:17:30 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

# ifdef __linux__
#  include <X11/keysym.h>
#  include <X11/X.h>
#  include "../minilibx-linux/mlx.h"
# else
#  include <Tk/X11/X.h>
#  include "../minilibx_opengl_20191021/mlx.h"
# endif

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "./enum.h"
# include "./define.h"
# include "./struct.h"
# include "./prototype.h"

#endif
