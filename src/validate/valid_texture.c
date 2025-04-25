/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/25 20:23:21 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Validates the image paths.
 * @param data The game data structure.
 * @param dir The array of image paths.
 * @return 1 if invalid, 0 if valid.
 * @details This function checks if the image paths are valid
 * and if they exist. It also checks if the paths are not empty
 * and if they have the correct extension.
 */
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

char	*set_dir(char *dir, int unuse, int *flag)
{
	char	**temp;
	char	*texture_dir;

	(void)unuse;
	temp = ft_split(dir, ' ');
	if (ft_arrlen(temp) != 2)
	{
		ft_free_strarr(temp);
		*flag = 1;
		error_msg(NULL, TEX_INVALID, 1, 0);
		return (NULL);
	}
	texture_dir = ft_strdup(temp[1]);
	ft_free_strarr(temp);
	return (texture_dir);
}

int	check_direction(t_game *data, char *dir, int *flag_n0_w1_s2_e3, int flag)
{
	if (!ft_strncmp(dir, "NO ", 3) && !flag_n0_w1_s2_e3[0])
	{
		data->tex_info.north = set_dir(dir, flag_n0_w1_s2_e3[0]++, &flag);
		return (flag);
	}
	else if (!ft_strncmp(dir, "WE ", 3) && !flag_n0_w1_s2_e3[1])
	{
		data->tex_info.west = set_dir(dir, flag_n0_w1_s2_e3[1]++, &flag);
		return (flag);
	}
	else if (!ft_strncmp(dir, "SO ", 3) && !flag_n0_w1_s2_e3[2])
	{
		data->tex_info.south = set_dir(dir, flag_n0_w1_s2_e3[2]++, &flag);
		return (flag);
	}
	else if (!ft_strncmp(dir, "EA ", 3) && !flag_n0_w1_s2_e3[3])
	{
		data->tex_info.east = set_dir(dir, flag_n0_w1_s2_e3[3]++, &flag);
		return (flag);
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
	int flag;

	if (ft_arrlen(dir) < 4)
		return (error_msg(NULL, TEX_MISSING, 1, 0));
	flag_n0_w1_s2_e3[0] = 0;
	flag_n0_w1_s2_e3[1] = 0;
	flag_n0_w1_s2_e3[2] = 0;
	flag_n0_w1_s2_e3[3] = 0;
	flag = 0;
	i = 0;
	while (dir[i] && i < 4)
		if (check_direction(data, dir[i++], flag_n0_w1_s2_e3, flag))
			return (1);
	return (0);
}
