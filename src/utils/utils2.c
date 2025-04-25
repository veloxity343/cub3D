/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:40:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/25 21:33:30 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

size_t	max_len(t_map *map, int i)
{
	size_t	len;
	size_t	max_len;

	max_len = ft_strlen(map->file[i]);
	while (map->file[++i])
	{
		len = ft_strlen(map->file[i]);
		if (len > max_len)
			max_len = len;
	}
	return (max_len);
}

/**
 * @brief Gets the map details such as width and height.
 * @param data The game data structure.
 * @param map The game map.
 * @details This function duplicates the map and calculates its width and height.
 */
void	get_map_details(t_game *data, char **map)
{
	int	i;

	i = -1;
	data->map = ft_arrdup(map);
	while (map[++i])
		if ((int)ft_strlen(map[i]) > data->map_info.w)
			data->map_info.w = ft_strlen(map[i]);
	data->map_info.h = i;
}

/**
 * @brief Checks if the player's position is valid.
 * @param map The game map.
 * @param x The x-coordinate of the player.
 * @param y The y-coordinate of the player.
 * @return 1 if valid, 0 otherwise.
 * @details Validates the player's position based on the surrounding tiles.
 * (e.g., walls, empty spaces). The player cannot be placed at the edges
 * of the map or in empty spaces.
 */
int	valid_player_pos(char **map, int x, int y)
{
	if (x == 0 || y == ft_arrlen(map)
		|| !map[y][x + 1] || map[y][x + 1] == ' '
		|| !map[y - 1][x] || map[y - 1][x] == ' ')
		return (1);
	return (0);
}

/**
 * @brief Sets the player's position and direction.
 * @param data The game data structure.
 * @param x The x-coordinate of the player.
 * @param y The y-coordinate of the player.
 * @return 1 if successful, INT_MIN if invalid position.
 * @details Updates the player's position and 
 * 		direction based on the given coordinates.
 * If the position is valid, it sets the player's position and direction.
 */
int	get_player_data(t_game *data, int x, int y)
{
	if (valid_player_pos(data->map, x, y))
		return (INT_MIN);
	data->player.pos.x = (double)x + 0.5;
	data->player.pos.y = (double)y + 0.5;
	data->player.dir = data->map[y][x];
	data->map[y][x] = '0';
	return (1);
}

/**
 * @brief Special check for edge case
 * @param map
 * @return 0 if valid, 1 if invalid.
 */
int	check_map_double_newline(char *map)
{
	char			**arr_map;
	int				i;
	char			*found_last_rgb;

	if (!map)
		return (1);
	arr_map = ft_split(map, '\n');
	i = ft_arrlen(arr_map) - 1;
	while (!ft_strnstr(arr_map[i], "F ", ft_strlen(arr_map[i])) && !ft_strnstr(arr_map[i], "C ", ft_strlen(arr_map[i])))
		i--;
	found_last_rgb = ft_strnstr(map, arr_map[i], ft_strlen(map))
		+ ft_strlen(arr_map[i]) + 1;
	ft_free_strarr(arr_map);
	i = 0;
	while (found_last_rgb[i] == '\n')
		i++;
	if (ft_strnstr(found_last_rgb + i, "\n\n", ft_strlen(found_last_rgb + i)))
		return (1);
	return (0);
}
