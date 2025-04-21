/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:28:50 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/21 18:31:18 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned long get(char *s_rgb)
{
    char **temp;
    unsigned int rgb[3];

    temp = ft_split(s_rgb, ',');
    rgb[0] = ft_atoi(temp[0]);
    rgb[1] = ft_atoi(temp[1]);
    rgb[2] = ft_atoi(temp[2]);
    ft_free_strarr(temp);
    if (rgb[0] < 256 && rgb[1] < 256 && rgb[2] < 256)
        return ((rgb[0] << 16) |( rgb[1] << 8) | rgb[2]);
    return (0);
}

int get_rgb(t_tex *ttx, char *floor, char *ceiling)
{
    ttx->hex_f = get(floor);
    ttx->hex_c = get(ceiling);
    if (ttx->hex_f == 0 || ttx->hex_c == 0)
        return (1);
    return (0);
}

int check_rgb(char *rgb)
{
    int i;
    int nbr0_cm1[2];

    i = -1;
    nbr0_cm1[0] = 0;
    nbr0_cm1[1] = 0;
    if (ft_strchr(rgb, ' '))
        return (1);
    while (rgb[++i])
    {
        if (ft_isdigit(rgb[i]))
            nbr0_cm1[0]++;
        else if (rgb[i] == ',')
        {
            nbr0_cm1[1]++;
            nbr0_cm1[0] = 0;
        }
        else
            return (1);
        if (nbr0_cm1[1] == 3 || nbr0_cm1[0] == 4)
            return (1);
    }
    if (nbr0_cm1[1] != 2)
        return 1;
    return (0);
}

int valid_rgb(t_game *data, char **rgb)
{
    if (!rgb[0] || !rgb[1])
        return (error_msg(NULL, COLOR_MISSING, 1, 0));
    if (ft_strncmp(rgb[0], "F ", 2) || ft_strncmp(rgb[1], "C ", 2))
        return (error_msg(NULL, COLOR_MISSING, 1, 0));
    if (check_rgb(rgb[0] + 2) || check_rgb(rgb[1] + 2))
        return (error_msg(NULL, COLOR_FLOOR_CEILING, 1, 0));
    if (get_rgb(&data->tex_info, rgb[0] + 2, rgb[1] + 2))
        return (error_msg(NULL, COLOR_FLOOR_CEILING, 1, 0));
    return (0);
}
