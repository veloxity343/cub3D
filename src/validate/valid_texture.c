// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   valid_texture.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/09 14:42:29 by yyan-bin          #+#    #+#             */
// /*   Updated: 2025/04/09 18:38:53 by yyan-bin         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../inc/cub3d.h"

// /**
//  * @brief Add texture dat to @param t_img
//  * @param img Texture data structer
//  * @param dir Texture path 2D array
//  * @param f Flag
//  * @param mlx_ptr Minilib pointer
//  * @return 1=error, 0=ok
//  */
// int    check(t_img *img, char *dir, int *f, void *mlx_ptr)
// {
//     *f = 42;
//     img->path = ft_substr(dir, 3, ft_strlen(dir) - 3);
//     img->img = mlx_xpm_file_to_image(mlx_ptr, img->path, \
//         &img->width, &img->height);
//     if (!img->img)
//         return (ft_error_msg(ERR_TEXT_PATH, 1));
//     img->addr = mlx_get_data_addr(img->img, &img->pixel_bits, \
//         &img->size_line, &img->endian);
//     if (!img->addr)
//         return (ft_error_msg(ERR_TEXT, 1));
//     return (0);
// }


// /**
//  * @brief Check texture syntax.
//  * @param data Main data structure
//  * @param dir Texture path 2D array
//  * @param flag_n0_w1_s2_e3 Direction flag
//  * index: 0=North, 1=West, 2=South, 3=East
//  * will open flag if found
//  * @return 1=error, 0=ok
//  */
// int check_direction(t_data *data, char *dir, int *flag_n0_w1_s2_e3)
// {
//     if (!ft_strncmp(dir, "NO ", 3) && !flag_n0_w1_s2_e3[0])
//         return (check(&data->n_img, dir, &flag_n0_w1_s2_e3[0], data->view.mlx));
//     else if (!ft_strncmp(dir, "WE ", 3) && !flag_n0_w1_s2_e3[1])
//         return (check(&data->w_img, dir, &flag_n0_w1_s2_e3[1], data->view.mlx));
//     else if (!ft_strncmp(dir, "SO ", 3) && !flag_n0_w1_s2_e3[2])
//         return (check(&data->s_img, dir, &flag_n0_w1_s2_e3[2], data->view.mlx));
//     else if (!ft_strncmp(dir, "EA ", 3) && !flag_n0_w1_s2_e3[3])
//         return (check(&data->e_img, dir, &flag_n0_w1_s2_e3[3], data->view.mlx));
//     return (ft_error_msg(ERR_TEXT, 1));
// }

// /**
//  * @brief Check is valid texture.
//  * Will store texture data.
//  * @param data Main data structure
//  * @param dir Texture 2D array path
//  * @return 1=error, 0=ok
//  */
// int valid_image(t_data *data, char **dir)
// {
//     int i;
//     int flag_n0_w1_s2_e3[4];

//     if (ft_arrlen(dir) < 4)
//         return (ft_error_msg(ERR_TEXT_MAP, 1));
//     flag_n0_w1_s2_e3[0] = 0;
//     flag_n0_w1_s2_e3[1] = 0;
//     flag_n0_w1_s2_e3[2] = 0;
//     flag_n0_w1_s2_e3[3] = 0;
//     i = 0;
//     while (dir[i] && i < 4)
//         if (check_direction(data, dir[i++], flag_n0_w1_s2_e3))
//             return (1);
//     return (0);
// }
