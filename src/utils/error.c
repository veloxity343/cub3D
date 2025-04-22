/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:27 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/22 23:22:36 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error2(int error)
{
	if (error == FILE_NOT_CUB)
		ft_putstr_fd("\e[31mFile error: Format is not .cub\n\e[0m", 2);
	else if (error == FILE_NOT_XPM)
		ft_putstr_fd("\e[31mFile error: Format is not .xpm\n\e[0m", 2);
	else if (error == FILE_IS_DIR)
		ft_putstr_fd("\e[31mFile error: Given argument is a directory\n\e[0m", 2);
	else if (error == COLOR_FLOOR_CEILING)
		ft_putstr_fd("\e[31mColour error: Invalid for floor/ceiling\n\e[0m", 2);
	else if (error == COLOR_FLOOR)
		ft_putstr_fd("\e[31mColour error: Invalid for floor\n\e[0m", 2);
	else if (error == COLOR_CEILING)
		ft_putstr_fd("\e[31mColour error: Invalid for ceiling\n\e[0m", 2);
	else if (error == COLOR_MISSING)
		ft_putstr_fd("\e[31mColour error: Missing colour(s)\n\e[0m", 2);
	else if (error == MAP_MISSING)
		ft_putstr_fd("\e[31mMap error: Missing map\n\e[0m", 2);
	else if (error == MAP_TOO_SMALL)
		ft_putstr_fd("\e[31mMap error: Need to be at least 3x3 map\n\e[0m", 2);
	else if (error == MAP_NO_WALLS)
		ft_putstr_fd("\e[31mMap error: Not surrounded by walls\n\e[0m", 2);
	else if (error == MAP_LAST)
		ft_putstr_fd("\e[31mMap error: Not the file's last element\e[0m", 2);
	else if (error == MAP_INVALID)
		ft_putstr_fd("\e[31mMap error: Invalid map\e[0m", 2);
}

static void	print_error1(int error)
{
	if (error == MLX_START)
		ft_putstr_fd("\e[31mMLX error: Cannot initiate mlx\n\e[0m", 2);
	else if (error == MLX_WIN)
		ft_putstr_fd("\e[31mMLX error: Cannot create window\n\e[0m", 2);
	else if (error == MLX_IMG)
		ft_putstr_fd("\e[31mMLX error: Cannot create image\n\e[0m", 2);
	else if (error == USER_NUM)
		ft_putstr_fd("\e[31mPlayer error: More than one player on map\n\e[0m",
			2);
	else if (error == USER_POS)
		ft_putstr_fd("\e[31mPlayer error: Invalid position\n\e[0m", 2);
	else if (error == USER_DIR)
		ft_putstr_fd("\e[31mPlayer error: No position (need N/S/E/W)\n\e[0m",
			2);
	else if (error == MALLOC)
		ft_putstr_fd("\e[31mMemory error: Cannot allocate memory\n\e[0m", 2);
	else if (error == USAGE)
		ft_putstr_fd("\e[31mUsage: ./cub3d <path/map.cub>\n\e[0m", 2);
	else if (error == TEX_MISSING)
		ft_putstr_fd("\e[31mTexture error: Missing texture\n\e[0m", 2);
	else if (error == TEX_INVALID)
		ft_putstr_fd("\e[31mTexture error: Invalid texture\n\e[0m", 2);
	else
		print_error2(error);
}

int	error_msg(char *info, int error, int code, int custom)
{
	ft_putendl_fd("\e[31mError", 2);
	if (custom)
	{
		ft_putstr_fd("\e[31m", 2);
		ft_putendl_fd(strerror(error), 2);
		ft_putstr_fd("\e[0m", 2);
	}
	else if (error == FILE_INVALID)
		ft_putstr_fd("\e[31mFile error: Can't open file\n\e[0m", 2);
	else if (error == FILE_INVALID_CHAR)
		ft_putstr_fd("\e[31mMap error: Invalid character in map\n\e[0m", 2);
	else
		print_error1(error);
	if (info)
		ft_putendl_fd(info, 2);
	return (code);
}
