/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:22:17 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/11 21:51:24 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Validate if map is surrounded by walls
 * Verify extreme rows then columns
 * @param data
 * @return true
 * @return false
 */
/* static bool	ft_is_map_sur_walls(t_data *data)
{
	int	i;
	int	j;
	int	col_size;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		col_size = ft_strlen(data->map[i]);
		while (data->map[i][++j])
		{
			while (ft_is_white_space(data->map[i][j]))
				data->map[i][j++] = C_WALL;
			if (i == 0 && data->map[i][j] != C_WALL)
				return (false);
			else if (i == data->map_det.height -1 && data->map[i][j] != C_WALL)
				return (false);
			else if (j == 0 && data->map[i][j] != C_WALL)
				return (false);
			else if (j == (col_size - 1) && data->map[i][j] != C_WALL)
				return (false);
		}
	}
	return (true);
} */

static bool	ft_is_map_sur_walls(t_data *data)
{
	int	i;
	int	j;
	int	width;
	int	height;

	width = data->map_det.width;
	height = data->map_det.height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				if (data->map[i][j] != C_WALL)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

/**
 * @brief Handle the character in map. 6 possible characters: 0 for an empty
 * space, 1 for a wall, and N,S,E or W for the player’s start position
 * @hint: Direction Player updated Here!
 * @param data Data structure
 * @param map Matrix representing map
 * @return int 0 OK. other wise: error
 */
static int	ft_is_valid_char_in_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	data->player.dir = C_BACK_G;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			while (ft_is_white_space(map[i][j]))
				j++;
			if ((ft_strchr(VALID_CHAR_MAP, map[i][j])) == NULL)
				return (ft_error_msg(ERR_MAP_CHAR, 10));
			if ((ft_strchr(VALID_PLAYER_POS, map[i][j])) != NULL)
			{
				if (data->player.dir != C_BACK_G)
					return (ft_error_msg(ERR_SING_PLAYER, 11));
				else
					data->player.dir = map[i][j];
			}
		}
	}
	return (0);
}

/**
 * @brief Map must be the last element in file. Verify if it is
 * @param map_det Map Detail Structure
 * @return boolean
 */
static bool	ft_is_map_last_element(t_map_det *map_det)
{
	int	i;
	int	j;

	i = map_det->end_i_map;
	while (map_det->file[i])
	{
		j = 0;
		while (map_det->file[i][j])
		{
			if (map_det->file[i][j] != ' ' && map_det->file[i][j] != '\t' &&
				map_det->file[i][j] != '\n' && map_det->file[i][j] != '\r' &&
				map_det->file[i][j] != '\v' && map_det->file[i][j] != '\f')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/**
 * @brief Update player position (Pos_X Pos_Y). The old space will received
 * 'empty' in map
 * @hint: Put plus 0.5 to get a better angles. Without, the idea of 3D will
 * be worst. Test without to verify
 * @param data Data Struct
 * @param map Map - Array representation
 * @return boolean
 */
static bool	ft_check_player_pos(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr(VALID_PLAYER_POS, map[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map[i][j] = C_BACK_G;
			}
			j++;
		}
		i++;
	}
	if (data->player.dir == C_BACK_G || ft_pos_is_valid(data, map) == FAILURE)
	{
		ft_error_msg(ERR_PLA_POS, 1);
		return (false);
	}
	return (true);
}

int	ft_valid_map(t_data *data)
{
	int	valid_char_map;

	data->map = ft_arrdup(data->cub_file + 6);
	data->player.dir = C_BACK_G;
	if (!data->map)
		return (ft_error_msg(ERR_MAP7, 7));
	if (ft_is_map_sur_walls(data) == false || ft_map_is_enclosed(data) == false)
		return (ft_error_msg(ERR_MAP8, 8));
	valid_char_map = ft_is_valid_char_in_map(data, data->map);
	if (valid_char_map != 0)
		return (valid_char_map);
	if (ft_is_map_last_element(&data->map_det) == false)
		return (ft_error_msg(ERR_MAP_LAST, 16));
	if (ft_check_player_pos(data, data->map) == false)
		return (FAILURE);
	if (data->player.dir == C_BACK_G)
		return (ft_error_msg(ERR_MAP_DIR, 17));
	return (0);
}
