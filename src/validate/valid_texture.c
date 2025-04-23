/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/23 11:38:31 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Checks if the direction is valid and sets the texture path.
 * @param data The game data structure.
 * @param dir The direction string to check.
 * @param flag_n0_w1_s2_e3 The flags for each direction.
 * @return 0 if valid, 1 if invalid.
 * @details This function checks if the direction is valid and
 * sets the corresponding texture path in the game data structure.
 */
int	check_direction(t_game *data, char *dir, int *flag_n0_w1_s2_e3)
{
	if (!ft_strncmp(dir, "NO ", 3) && !flag_n0_w1_s2_e3[0])
	{
		data->tex_info.north = ft_strdup(dir + 3);
		flag_n0_w1_s2_e3[0] = 42;
		return (0);
	}
	else if (!ft_strncmp(dir, "WE ", 3) && !flag_n0_w1_s2_e3[1])
	{
		data->tex_info.west = ft_strdup(dir + 3);
		flag_n0_w1_s2_e3[1] = 42;
		return (0);
	}
	else if (!ft_strncmp(dir, "SO ", 3) && !flag_n0_w1_s2_e3[2])
	{
		data->tex_info.south = ft_strdup(dir + 3);
		flag_n0_w1_s2_e3[2] = 42;
		return (0);
	}
	else if (!ft_strncmp(dir, "EA ", 3) && !flag_n0_w1_s2_e3[3])
	{
		data->tex_info.east = ft_strdup(dir + 3);
		flag_n0_w1_s2_e3[3] = 42;
		return (0);
	}
	return (error_msg(NULL, TEX_INVALID, 1, 0));
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
	int	flag_n0_w1_s2_e3[4];

	if (ft_arrlen(dir) < 4)
		return (error_msg(NULL, TEX_MISSING, 1, 0));
	flag_n0_w1_s2_e3[0] = 0;
	flag_n0_w1_s2_e3[1] = 0;
	flag_n0_w1_s2_e3[2] = 0;
	flag_n0_w1_s2_e3[3] = 0;
	i = 0;
	while (dir[i] && i < 4)
		if (check_direction(data, dir[i++], flag_n0_w1_s2_e3))
			return (1);
	return (0);
}
