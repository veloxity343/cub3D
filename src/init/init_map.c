/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:38 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:18:41 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(t_game *game, char **file, int i)
{
	int	start;

	start = i;
	while (file[i] && file[i][ft_strspn(file[i], " \t\r\v\f")] == '1')
		i++;
	game->map_info.eom = i;
	return (i - start);
}

static int	fill_tab(t_map *map_info, char **map_tab, int index)
{
	int	i;
	int	j;

	i = 0;
	map_info->w = max_len(map_info, index);
	while (i < map_info->h)
	{
		j = 0;
		map_tab[i] = malloc((map_info->w + 1));
		if (!map_tab[i])
			return (error_msg("map: fill_tab", MALLOC, FAILURE, 0));
		while (map_info->file[index][j] && map_info->file[index][j] != '\n')
		{
			map_tab[i][j] = map_info->file[index][j];
			j++;
		}
		memset(&map_tab[i][j], '\0', map_info->w - j);
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (SUCCESS);
}

static int	get_info(t_game *game, char **file, int i)
{
	game->map_info.h = count_lines(game, file, i);
	game->map = malloc(sizeof(char *) * (game->map_info.h + 1));
	if (!game->map)
		return (error_msg("map: get_info", MALLOC, FAILURE, 0));
	return (fill_tab(&game->map_info, game->map, i));
}

static void	create_wall(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (game->map[i])
	{
		j = ft_strspn(game->map[i], " \t\r\v\f");
		len = ft_strlen(game->map[i]) - 1;
		while (game->map[i][++j])
			if (game->map[i][j] == ' ' && j != len)
				game->map[i][j] = '1';
		i++;
	}
}

int	create_map(t_game *game, char **file, int i)
{
	if (get_info(game, file, i) == FAILURE)
		return (FAILURE);
	create_wall(game);
	return (SUCCESS);
}
