/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:28:50 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/29 00:07:55 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Get RGB details
 * @param s_rgb RGB data string
 * @return unsigned long RGB data, return 0 if error
 */
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

/**
 * @brief Get RGB details
 * @param ttr t_texture_det structure
 * @param floor floor string
 * @param ceiling ceiling string
 * @return 1=error, 0=ok
 */
int get_rgb(t_texture_det *ttr, char *floor, char *ceiling)
{
    ttr->hex_floor = get(floor);
    ttr->hex_ceiling = get(ceiling);
    if (ttr->hex_floor == 0 || ttr->hex_ceiling == 0)
        return (1);
    return (0);
}

/**
 * @brief Check is valid RGB seting
 * @param rgb rgb seting string 
 * @return 1=error, 0=ok
 * @note variable nbr0_cm1
 * index: 0=number count, 1=comma count
 */
int check_rgb(char *rgb)
{
    int i;
    int nbr0_cm1[2];

    i = -1;
    nbr0_cm1[0] = 0;
    nbr0_cm1[1] = 0;
    if (ft_strchr(rgb, ' '))
        return (ft_error_msg(ERR_RGB_VAL, 1));
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
            return (ft_error_msg(ERR_RGB_VAL, 1));
        if (nbr0_cm1[1] == 3 || nbr0_cm1[0] == 4)
            return (ft_error_msg(ERR_RGB_VAL, 1));
    }
    if (nbr0_cm1[1] != 2)
        return (ft_error_msg(ERR_RGB, 1));
    return (0);
}

/**
 * @brief Check is valid RGB data
 * @param data Main data structure
 * @param rgb RGB 2D array
 * @return 1=error, 0=ok
 */
int valid_rgb(t_data *data, char **rgb)
{
    if (!rgb[0] || !rgb[1])
        return (ft_error_msg(ERR_RGB, 1));
    if (ft_strncmp(rgb[0], "F ", 2) || ft_strncmp(rgb[1], "C ", 2))
        return (ft_error_msg(ERR_RGB, 1));
    if (check_rgb(rgb[0] + 2) || check_rgb(rgb[1] + 2))
        return (1);
    if (get_rgb(&data->texture_det, rgb[0] + 2, rgb[1] + 2))
        return (ft_error_msg(ERR_RGB_VAL, 1));
    return (0);
}
