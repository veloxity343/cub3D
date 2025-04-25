/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/25 15:15:43 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Sets direction texture path.
 * @param data The game data structure.
 * @param dir The direction string to check.
 * @details This function sets the corresponding texture path in 
 * 		the game data structure.
 */
void	get_direction(t_game *data, char *dir)
{
	if (!ft_strncmp(dir, "NO ", 3))
		data->tex_info.north = ft_strdup(dir + 3);
	else if (!ft_strncmp(dir, "WE ", 3))
		data->tex_info.west = ft_strdup(dir + 3);
	else if (!ft_strncmp(dir, "SO ", 3))
		data->tex_info.south = ft_strdup(dir + 3);
	else if (!ft_strncmp(dir, "EA ", 3))
		data->tex_info.east = ft_strdup(dir + 3);
}

/**
 * @brief Validates the image paths.
 * @param data The game data structure.
 * @param dir The array of image paths.
 * @return 1 if invalid, 0 if valid.
 * @details This function checks if the image paths are valid
 * and if they exist. It also checks if the paths are not empty
 * and if they have the correct extension.
 */
int	valid_image(t_game *data, char **dir)
{
	int	i;

	if (ft_arrlen(dir) < 4)
		return (error_msg(NULL, TEX_MISSING, 1, 0));
	if (ft_strncmp(dir[0], "NO ", 3) || ft_strncmp(dir[1], "SO ", 3)
		|| ft_strncmp(dir[2], "WE ", 3)
		|| ft_strncmp(dir[3], "EA ", 3))
		return (error_msg(NULL, TEX_INVALID, 1, 0));
	i = 0;
	while (dir[i] && i < 4)
		get_direction(data, dir[i++]);
	return (0);
}
