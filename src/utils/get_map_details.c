/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_details.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:40:44 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/16 11:30:50 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

int valid_player_pos(char **map, int x, int y)
{
    if (x == 0 || y == ft_arrlen(map) || \
        !map[y][x + 1] || map[y][x  + 1] == ' ' || \
        !map[y - 1][x] || map[y - 1][x] == ' ')
        return (1);
    return (0);
}

int get_player_data(t_data *data, int x, int y)
{
    if (valid_player_pos(data->map, x, y))
        return (INT_MIN);
    data->player.pos_x = (double)x + 0.5;
    data->player.pos_y = (double)y + 0.5;
    data->map[y][x] = '1';
    return (1);
}