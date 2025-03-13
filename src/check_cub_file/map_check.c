#include "../../inc/cub3d.h"

int check_x_help(char *map, int x, int f)
{
    if (map[x + f])
        if (map[x + f] == '0' || !ft_strchr("01NWSE ", map[x + f]))
            return (1);
    return (0);
}

int check_y_help(char **map, int x, int y, int f)
{
    if (!map[y + f] || (y == 0 && f == -1))
        return (0);
    if (map[y + 1])
        if (ft_strlen(map[y + 1]) < x)
            return (0);
    if (map[y + f][x])
        if (map[y + f][x] == '0' || !ft_strchr("01NWSE ", map[y + f][x]))
            return (1);
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
            return (1);
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

int check_map(t_data *data, char **map)
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
    else if (player != 1)
        return (ft_error_msg(ERR_SING_PLAYER, 1));
    return (0);
}
