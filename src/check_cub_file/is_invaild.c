/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invaild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/09 16:03:13 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static char    **read_map(char *path)
{
    int fd;
    char    *temp;
    char    *readd;
    char    **cub_file;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    temp = get_next_line(fd);
    readd = ft_calloc(1, 1);
    while (temp)
    {
        readd = ft_strjoin_free(readd, temp);
        ft_free1(temp);
        temp = get_next_line(fd);
    }
    cub_file = ft_split(readd, '\n');
    if (!cub_file)
        return (NULL);
    ft_free1(readd);
    return (cub_file);
}

int    check(t_img *img, char *dir, int *f)
{
    img->path = ft_substr(dir, 3, ft_strlen(dir) - 3);
    *f = 42;
    return (0);
}

int check_direction(t_data *data, char *dir)
{
    if (!ft_strncmp(dir, "NO ", 3) && !data->flag_n0_w1_s2_e3[0])
        return (check(&data->n_img, dir, &data->flag_n0_w1_s2_e3[0]));
    else if (!ft_strncmp(dir, "WE ", 3) && !data->flag_n0_w1_s2_e3[1])
        return (check(&data->w_img, dir, &data->flag_n0_w1_s2_e3[1]));
    else if (!ft_strncmp(dir, "SO ", 3) && !data->flag_n0_w1_s2_e3[2])
        return (check(&data->s_img, dir, &data->flag_n0_w1_s2_e3[2]));
    else if (!ft_strncmp(dir, "EA ", 3) && !data->flag_n0_w1_s2_e3[3])
        return (check(&data->e_img, dir, &data->flag_n0_w1_s2_e3[3]));
    return (1);
}

int init_img(t_data *data, char **dir)
{
    int i;

    i = -1;
    while (dir[++i])
        if (check_direction(data, dir[i]))
            return (1);
    return (0);
}

int is_invalid(t_data *data, char *path)
{
    char    **file;

    data->cub_file = read_map(path);
    if (!data->cub_file)
        return (1);
    if (ft_arrlen(data->cub_file) < 4)
        return (1);
    file = ft_arrdup_n(data->cub_file, 4);
    if (!file || init_img(data, file))
        return (1);
    ft_free_strarr(file);
    // file = ft_arrdup_n(data->cub_file + 4, 2);
    // if (!file || init_rgb(data, file))
    //     return (1);
    return (0);
}
