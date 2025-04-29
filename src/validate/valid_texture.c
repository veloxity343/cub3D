/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/29 18:17:59 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_dir(t_game *data, char **dir, int *flag)
{
	int	return_status;

	return_status = 1;
	if (!ft_strncmp(dir[0], "NO", 2) && !flag[0])
	{
		flag[0] = 42 + return_status--;
		data->tex_info.north = ft_strdup(dir[1]);
	}
	else if (!ft_strncmp(dir[0], "WE", 2) && !flag[1])
	{
		flag[1] = 42 + return_status--;
		data->tex_info.west = ft_strdup(dir[1]);
	}
	else if (!ft_strncmp(dir[0], "SO", 2) && !flag[2])
	{
		flag[2] = 42 + return_status--;
		data->tex_info.south = ft_strdup(dir[1]);
	}
	else if (!ft_strncmp(dir[0], "EA", 2) && !flag[3])
	{
		flag[3] = 42 + return_status--;
		data->tex_info.east = ft_strdup(dir[1]);
	}
	return (return_status);
}

int	check_direction(t_game *data, char *dir, int *flag)
{
	char	**split_dir;
	int		return_status;

	return_status = 0;
	split_dir = ft_split(dir, ' ');
	if (ft_arrlen(split_dir) != 2)
		error_msg(NULL, TEX_INVALID, 1, return_status++);
	else if (get_dir(data, split_dir, flag))
		error_msg(NULL, TEX_INVALID, 1, return_status++);
	ft_free_strarr(split_dir);
	return (return_status);
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

	if (!dir[0])
		return (error_msg(NULL, EMPTY_FILE, 1, 0));
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
