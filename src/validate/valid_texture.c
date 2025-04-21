/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/21 18:25:39 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_direction(t_game *data, char *dir, int *flag_n0_w1_s2_e3)
{
    if (!ft_strncmp(dir, "NO ", 3) && !flag_n0_w1_s2_e3[0])
    {
        data->tex_info.north = ft_strdup(dir + 3);
        flag_n0_w1_s2_e3[0] = 42;
        return (0);
    }
    else if (!ft_strncmp(dir, "WE ", 3) && !flag_n0_w1_s2_e3[1])
    {
        data->tex_info.west = ft_strdup(dir + 3);
        flag_n0_w1_s2_e3[1] = 42;
        return (0);
    }
    else if (!ft_strncmp(dir, "SO ", 3) && !flag_n0_w1_s2_e3[2])
    {
        data->tex_info.south = ft_strdup(dir + 3);
        flag_n0_w1_s2_e3[2] = 42;
        return (0);
    }
    else if (!ft_strncmp(dir, "EA ", 3) && !flag_n0_w1_s2_e3[3])
    {
        data->tex_info.east = ft_strdup(dir + 3);
        flag_n0_w1_s2_e3[3] = 42;
        return (0);
    }
    return (error_msg(NULL, TEX_INVALID, 1, 0));
}

int valid_image(t_game *data, char **dir)
{
    int i;
    int flag_n0_w1_s2_e3[4];

    if (ft_arrlen(dir) < 4)
        return (error_msg(NULL, TEX_MISSING, 1, 0));
    flag_n0_w1_s2_e3[0] = 0;
    flag_n0_w1_s2_e3[1] = 0;
    flag_n0_w1_s2_e3[2] = 0;
    flag_n0_w1_s2_e3[3] = 0;
    i = 0;
    while (dir[i] && i < 4)
        if (check_direction(data, dir[i++], flag_n0_w1_s2_e3))
            return (1);
    return (0);
}
