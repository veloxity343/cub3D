/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:40:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/21 22:00:44 by yyan-bin         ###   ########.fr       */
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

int	valid_player_pos(char **map, int x, int y)
{
	if (x == 0 || y == ft_arrlen(map) || \
		!map[y][x + 1] || map[y][x + 1] == ' ' || \
		!map[y - 1][x] || map[y - 1][x] == ' ')
		return (1);
	return (0);
}

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
