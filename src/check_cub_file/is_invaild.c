/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invaild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/11 22:12:54 by yyan-bin         ###   ########.fr       */
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

int    check(t_img *img, char *dir, int *f, void *mlx_ptr)
{
    *f = 42;
    img->path = ft_substr(dir, 3, ft_strlen(dir) - 3);
    img->img = mlx_xpm_file_to_image(mlx_ptr, img->path, \
        &img->width, &img->height);
    if (!img->img)
        return (ft_error_msg(ERR_TEXT_PATH, 1));
    img->addr = mlx_get_data_addr(img->img, &img->pixel_bits, \
        &img->size_line, &img->endian);
    if (!img->addr)
        return (ft_error_msg(ERR_TEXT, 1));
    return (0);
}

int check_direction(t_data *data, char *dir, int *flag_n0_w1_s2_e3)
{
    if (!ft_strncmp(dir, "NO ", 3) && !flag_n0_w1_s2_e3[0])
        return (check(&data->n_img, dir, &flag_n0_w1_s2_e3[0], data->window.mlx));
    else if (!ft_strncmp(dir, "WE ", 3) && !flag_n0_w1_s2_e3[1])
        return (check(&data->w_img, dir, &flag_n0_w1_s2_e3[1], data->window.mlx));
    else if (!ft_strncmp(dir, "SO ", 3) && !flag_n0_w1_s2_e3[2])
        return (check(&data->s_img, dir, &flag_n0_w1_s2_e3[2], data->window.mlx));
    else if (!ft_strncmp(dir, "EA ", 3) && !flag_n0_w1_s2_e3[3])
        return (check(&data->e_img, dir, &flag_n0_w1_s2_e3[3], data->window.mlx));
    return (ft_error_msg(ERR_TEXT, 1));
}

int init_image(t_data *data, char **dir)
{
    int i;
    int flag_n0_w1_s2_e3[4];

    if (ft_arrlen(dir) < 4)
        return (ft_error_msg(ERR_TEXT_MAP, 1));
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

int is_invalid(t_data *data, char *path)
{
    data->cub_file = read_map(path);
    if (!data->cub_file)
        return (ft_error_msg(ERR_TEXT_MAP, 1));
    if (init_image(data, data->cub_file))
        return (1);
    if (init_rgb(data, data->cub_file + 4))
        return (1);
    return (0);
}
