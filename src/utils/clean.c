/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:40:54 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/09 20:49:25 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Free the textures structure
 * @param texture Texture Structure
 */
static void	ft_free_textures(t_texture_det *texture)
{
	if (texture->north)
		ft_free1(texture->north);
	if (texture->south)
		ft_free1(texture->south);
	if (texture->west)
		ft_free1(texture->west);
	if (texture->east)
		ft_free1(texture->east);
	if (texture->floor)
		ft_free1(texture->floor);
	if (texture->ceiling)
		ft_free1(texture->ceiling);
}

/**
 * @brief Garbage collector to handle map detail variables
 * @param data Data structure (passed by ref)
 */
static void	ft_free_map(t_data *data)
{
	if (data->map_det.fd > 0)
		close(data->map_det.fd);
	if (data->map_det.file)
		ft_free_strarr(data->map_det.file);
	if (data->map)
		ft_free_strarr(data->map);
}

void	free_img(t_img *img)
{
	if (img->addr)
		ft_free1(img->addr);
	if (img->path)
		ft_free1(img->path);
}

int	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->textures)
			ft_free_intarr(data->textures);
		if (data->texture_pixels)
			ft_free_intarr(data->texture_pixels);
		ft_free_textures(&data->texture_det);
		ft_free_map(data);
		debug(100000000);
	}
	return (EXIT_FAILURE);
}
