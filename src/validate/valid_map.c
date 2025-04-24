/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:56:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/24 13:33:03 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_x_help(char *map, int x, int f)
{
	if (x + f < 0 || x + f > (int)ft_strlen(map))
		return (0);
	if (map[x + f])
	{
		if (map[x + f] == '0')
			return (error_msg(NULL, MAP_NO_WALLS, 1, 0));
		if (!ft_strchr("01 ", map[x + f]))
			return (error_msg(NULL, FILE_INVALID_CHAR, 1, 0));
	}
	return (0);
}

int	check_y_help(char **map, int x, int y, int f)
{
	if (y + f < 0 || y + f >= ft_arrlen(map) || x >= (int)ft_strlen(map[y + f]))
		return (0);
	if (map[y + f][x])
	{
		if (map[y + f][x] == '0')
			return (error_msg(NULL, MAP_NO_WALLS, 1, 0));
		if (!ft_strchr("01 ", map[y + f][x]))
			return (error_msg(NULL, FILE_INVALID_CHAR, 1, 0));
	}
	return (0);
}

/**
 * @brief Checks if the x-coordinate (horizontal plane)
 * of the map is valid.
 * @param map The map to check.
 * @param x The x-coordinate to check.
 * @return 1 if valid, 0 otherwise.
 * @details This function checks if the x-coordinate is a
 * wall or empty space. If it is empty, it checks the surrounding
 * coordinates to ensure they are walls. If it is a wall,
 * it checks if the bordering coordinates are valid.
 */
int	check_x(char *map, int x)
{
	if (map[x] == ' ')
	{
		if (check_x_help(map, x, 1) || check_x_help(map, x, -1))
			return (1);
	}
	else if (map[x] == '0')
	{
		if (!map[x + 1] || !map[x - 1])
			return (error_msg(NULL, MAP_NO_WALLS, 1, 0));
	}
	else if (!ft_strchr("10NSEW", map[x]))
		return (error_msg(NULL, FILE_INVALID_CHAR, 1, 0));
	return (0);
}

/**
 * @brief Checks if the y-coordinate (vertical plane)
 * of the map is valid.
 * @param map The map to check.
 * @param x The x-coordinate to check.
 * @param y The y-coordinate to check.
 * @return 1 if valid, 0 otherwise.
 * @details This function checks if the y-coordinate is a
 * wall or empty space. If it is empty, it checks the surrounding
 * coordinates to ensure they are walls. If it is a wall,
 * it checks if the bordering coordinates are valid.
 */
int	check_y(char **map, int x, int y)
{
	if (map[y][x] == ' ')
	{
		if (check_y_help(map, x, y, 1) || check_y_help(map, x, y, -1))
			return (1);
	}
	else if (map[y][x] == '0')
	{
		if (y == 0 || !map[y + 1] || !map[y + 1][x] || !map[y - 1][x])
			return (error_msg(NULL, MAP_NO_WALLS, 1, 0));
	}
	else if (!ft_strchr("10NSEW", map[y][x]))
		return (error_msg(NULL, FILE_INVALID_CHAR, 1, 0));
	return (0);
}

/**
 * @brief Validates the map for player position and wall structure.
 * @param data Pointer to the game structure.
 * @param map The map to validate.
 * @return 0 if valid, 1 if invalid.
 * @details This function checks if the map is surrounded by walls,
 * 		if the player is positioned correctly, 
 * 		and if there are any invalid characters.
 * 		It also ensures that there is exactly one player on the map.
 */
int	valid_map(t_game *data, char **map)
{
	int	x;
	int	y;
	int	player;

	y = -1;
	player = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NSEW", map[y][x]))
				player += get_player_data(data, x, y);
			if (check_x(map[y], x) || check_y(map, x, y))
				return (1);
		}
	}
	if (player == 0)
		return (error_msg(NULL, USER_DIR, 1, 0));
	else if (player < 0)
		return (error_msg(NULL, USER_POS, 1, 0));
	else if (player != 1)
		return (error_msg(NULL, USER_NUM, 1, 0));
	return (0);
}
