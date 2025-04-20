/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:16:43 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:16:48 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_elements(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	game->player.dir = '0';
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (ft_strchr(" \t\r\v\f", game->map[i][j]))
				j++;
			if (!ft_strchr("10NSEW", map_tab[i][j]))
				return (error_msg(
						game->map_info.path, FILE_INVALID_CHAR, FAILURE, 0));
			if (ft_strchr("NSEW", map_tab[i][j]) && game->player.dir != '0')
				return (error_msg(game->map_info.path, USER_NUM, FAILURE, 0));
			if (ft_strchr("NSEW", map_tab[i][j]))
				game->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	validate_position(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	i = (int)game->player.pos.y;
	j = (int)game->player.pos.x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| is_whitespace(map_tab[i][j - 1])
		|| is_whitespace(map_tab[i][j + 1])
		|| is_whitespace(map_tab[i - 1][j])
		|| is_whitespace(map_tab[i + 1][j]))
		return (FAILURE);
	return (SUCCESS);
}

static int	validate_player_pos(t_game *game, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	if (game->player.dir == '0')
		return (error_msg(game->map_info.path, USER_DIR, FAILURE, 0));
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				game->player.pos.x = (double)j + 0.5;
				game->player.pos.y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (validate_position(game, map_tab) == FAILURE)
		return (error_msg(game->map_info.path, USER_POS, FAILURE, 0));
	return (SUCCESS);
}

static int	validate_end_file(t_map *map)
{
	int	i;
	int	j;

	i = map->eom;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (!ft_strchr(" \t\r\n\v\f", map->file[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	validate_map(t_game *game, char **map_tab)
{
	if (!game->map)
		return (error_msg(game->map_info.path, MAP_MISSING, FAILURE, 0));
	if (validate_sides(&game->map_info, map_tab) == FAILURE)
		return (error_msg(game->map_info.path, MAP_NO_WALLS, FAILURE, 0));
	if (game->map_info.h < 3)
		return (error_msg(game->map_info.path, MAP_TOO_SMALL, FAILURE, 0));
	if (validate_elements(game, map_tab) == FAILURE
		|| validate_player_pos(game, map_tab) == FAILURE
		|| validate_end_file(&game->map_info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
