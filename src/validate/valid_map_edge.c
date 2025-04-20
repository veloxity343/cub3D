/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:16:59 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:17:02 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_top_bottom(char **map_tab, int i)
{
	int	j;

	j = 0;
	if (!map_tab || !map_tab[i])
		return (FAILURE);
	while (ft_strchr(" \t\r\v\f", map_tab[i][j]))
		j++;
	while (map_tab[i][j])
		if (map_tab[i][j++] != '1')
			return (FAILURE);
	return (SUCCESS);
}

int	validate_sides(t_map *map, char **map_tab)
{
	int	i;
	int	j;

	i = 1;
	if (validate_top_bottom(map_tab, 0) == FAILURE
		|| validate_top_bottom(map_tab, map->h - 1) == FAILURE)
		return (FAILURE);
	while (i < map->h - 1)
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i++][j] != '1')
			return (FAILURE);
	}
	return (SUCCESS);
}
