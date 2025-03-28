/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_details.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:40:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/29 00:33:37 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Get map width and height data
 * @param data Main data structer
 * @param map Map 2D array
 */
void    get_map_details(t_data *data, char **map)
{
    int i;

    i = -1;
    data->map = ft_arrdup(map);
    while (map[++i])
        if (ft_strlen(map[i]) > data->map_det.width)
            data->map_det.width = ft_strlen(map[i]);
    data->map_det.height = i;
}

/**
 * @brief Check is valid player position 
 * @param map Map 2D array
 * @param x Player X-axis
 * @param y Player Y-axis
 * @return 1=error 0=ok
 */
int valid_player_pos(char **map, int x, int y)
{
    if (x == 0 || y == ft_arrlen(map) || \
        !map[y][x + 1] || map[y][x  + 1] == ' ' || \
        !map[y - 1][x] || map[y - 1][x] == ' ')
        return (1);
    return (0);
}

/**
 * @brief Get player data
 * @param data Main data structure
 * @param x Player X-axis
 * @param y Player Y-axis
 * @return INT_MAX if player position invalid
 */
int get_player_data(t_data *data, int x, int y)
{
    if (valid_player_pos(data->map, x, y))
        return (INT_MIN);
    data->player.pos_x = (double)x + 0.5;
    data->player.pos_y = (double)y + 0.5;
    data->map[y][x] = '1';
    return (1);
}