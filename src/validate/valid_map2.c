/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:20:42 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/11 22:04:39 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Allocate memory for the visited matrix.
 * @param width Map width.
 * @param height Map height.
 * @return Pointer to the allocated matrix.
 */
bool **allocate_visited_matrix(int width, int height)
{
	int i;
	bool **visited;
	
	visited = (bool **)malloc(height * sizeof(bool *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = (bool *)malloc(width * sizeof(bool));
		if (!visited[i])
		{
			free_visited_matrix(visited, i);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

/**
 * @brief Free memory allocated for the visited matrix.
 * @param visited Pointer to the visited matrix.
 * @param height Map height.
 */
void free_visited_matrix(bool **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

/**
 * @brief Flood-fill to check if any VALID_CHAR_MAP character can reach outside.
 * @param map The map matrix
 * @param visited Matrix tracking visited positions
 * @param x Current x position
 * @param y Current y position
 * @param width Map width
 * @param height Map height
 * @return true if a valid character leaks outside, false if enclosed
 */
static bool	ft_flood_fill(char **map, bool **visited, int x, int y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (true);
	if (visited[y][x] || map[y][x] == C_WALL || map[y][x] == ' ' || !ft_strchr(VALID_CHAR_MAP, map[y][x]))
		return (false);
	visited[y][x] = true;
	if (ft_flood_fill(map, visited, x + 1, y, width, height) ||
		ft_flood_fill(map, visited, x - 1, y, width, height) ||
		ft_flood_fill(map, visited, x, y + 1, width, height) ||
		ft_flood_fill(map, visited, x, y - 1, width, height))
		return (true);
	return (false);
}

/**
 * @brief Ensures all characters in VALID_CHAR_MAP are enclosed by walls.
 * @param data Game data structure
 * @return true if all required characters are enclosed, false otherwise
 */
bool	ft_map_is_enclosed(t_data *data)
{
	bool	**visited;
	int		i;
	int		j;
	int		width;
	int		height;

	width = data->map_det.width;
	height = data->map_det.height;
	visited = allocate_visited_matrix(width, height);
	if (!visited)
		return (false);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (ft_strchr(VALID_CHAR_MAP, data->map[i][j]) && !visited[i][j])
			{
				if (ft_flood_fill(data->map, visited, j, i, width, height))
				{
					free_visited_matrix(visited, height);
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	free_visited_matrix(visited, height);
	return (true);
}
