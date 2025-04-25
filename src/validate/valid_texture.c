// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/25 20:37:46 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// /**
//  * @brief Validates the image paths.
//  * @param data The game data structure.
//  * @param dir The array of image paths.
//  * @return 1 if invalid, 0 if valid.
//  * @details This function checks if the image paths are valid
//  * and if they exist. It also checks if the paths are not empty
//  * and if they have the correct extension.
//  */
// int	valid_image(t_game *data, char **dir)
// {
// 	if (ft_arrlen(dir) < 4)
// 		return (error_msg(NULL, TEX_MISSING, 1, 0));
// 	if (ft_strncmp(dir[0], "NO ", 3) || ft_strncmp(dir[1], "SO ", 3)
// 		|| ft_strncmp(dir[2], "WE ", 3)
// 		|| ft_strncmp(dir[3], "EA ", 3))
// 		return (error_msg(NULL, TEX_INVALID, 1, 0));
// 	data->tex_info.north = ft_strdup(dir[0] + 3);
// 	data->tex_info.west = ft_strdup(dir[1] + 3);
// 	data->tex_info.south = ft_strdup(dir[2] + 3);
// 	data->tex_info.east = ft_strdup(dir[3] + 3);
// 	return (0);
// }

static char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	return (str);
}

static int	store_texture(char **target, char *raw)
{
	char *clean = ft_strdup(skip_spaces(raw));
	if (!clean)
		return (error_msg(NULL, TEX_INVALID, 1, 0));
	*target = clean;
	return (0);
}

int	check_direction(t_game *data, char *dir, int *flag)
{
	char	*line = skip_spaces(dir);

	if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t') && !flag[0])
	{
		flag[0] = 42;
		return (store_texture(&data->tex_info.north, line + 2));
	}
	if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t') && !flag[1])
	{
		flag[1] = 42;
		return (store_texture(&data->tex_info.west, line + 2));
	}
	if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t') && !flag[2])
	{
		flag[2] = 42;
		return (store_texture(&data->tex_info.south, line + 2));
	}
	if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t') && !flag[3])
	{
		flag[3] = 42;
		return (store_texture(&data->tex_info.east, line + 2));
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
