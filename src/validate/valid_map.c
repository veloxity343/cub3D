/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:56:18 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/16 11:28:54 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_x_help(char *map, int x, int f)
{
    if (x + f < 0 || x + f > ft_strlen(map))
        return (0);
    if (map[x + f])
    {
        if (map[x + f] == '0')
            return (ft_error_msg(ERR_MAP8, 1));
        if (!ft_strchr("01 ", map[x + f]))
            return (ft_error_msg(ERR_MAP_CHAR, 1));
    }
    return (0);
}

int check_y_help(char **map, int x, int y, int f)
{
    if (y + f < 0 || y + f >= ft_arrlen(map) || x >= ft_strlen(map[y + f]))
        return (0);
    if (map[y + f][x])
    {
        if (map[y + f][x] == '0')
            return (ft_error_msg(ERR_MAP8, 1));
        if (!ft_strchr("01 ", map[y + f][x]))
            return (ft_error_msg(ERR_MAP_CHAR, 1));
    }
    return (0);
}

int check_x(char *map, int x)
{
    if (map[x] == ' ')
    {
        if (check_x_help(map, x, 1) || check_x_help(map, x, -1))
            return (1);
    }
    else if (map[x] == '0')
    {
        if (!map[x + 1] || !map[x - 1])
            return (ft_error_msg(ERR_MAP8, 1));
    }
    else if (!ft_strchr(VALID_CHAR_MAP, map[x]))
        return (ft_error_msg(ERR_MAP9, 1));
    return (0);
}

int check_y(char **map, int x, int y)
{
    if (map[y][x] == ' ')
    {
        if (check_y_help(map, x, y, 1) || check_y_help(map, x, y, -1))
            return (1);
    }
    else if (map[y][x] == '0')
    {
        if (y == 0 || !map[y + 1] || !map[y + 1][x] || !map[y - 1][x])
            return (ft_error_msg(ERR_MAP8, 1));
    }
    else if (!ft_strchr(VALID_CHAR_MAP, map[y][x]))
        return (ft_error_msg(ERR_MAP9, 1));
    return (0);
}

int valid_map(t_data *data, char **map)
{
    int x;
    int y;
    int player;

    y = -1;
    player = 0;
    while (map[++y])
    {
        x = -1;
        while (map[y][++x])
        {
            if (ft_strchr(VALID_PLAYER_POS, map[y][x]))
                player += get_player_data(data, x, y);
            if (check_x(map[y], x) || check_y(map, x, y))
                return (1);
        }
    }
    if (player == 0)
        return (ft_error_msg(ERR_MAP_DIR, 1));
    else if (player < 0)
        return (ft_error_msg(ERR_PLA_POS, 1));
    else if (player != 1)
        return (ft_error_msg(ERR_SING_PLAYER, 1));
    return (0);
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
