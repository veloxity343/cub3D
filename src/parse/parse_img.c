/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:00:49 by rcheong           #+#    #+#             */
/*   Updated: 2025/02/16 16:01:36 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_data *data, t_img *i, int width, int height)
{
	i->img = mlx_new_image(data->window.mlx, width, height);
	if (i->img == NULL)
		exit_and_free(data, error_msg(ERR_MLX_IMG, 20));
	i->addr = (int *)mlx_get_data_addr(i->img, &i->pixel_bits,
			&i->size_line, &i->endian);
	return ;
}

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->window.mlx, path,
			&data->texture_det.size, &data->texture_det.size);
	if (image->img == NULL)
		exit_and_free(data, error_msg(ERR_MLX_IMG, 21));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}
