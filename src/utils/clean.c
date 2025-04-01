/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:40:54 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/16 11:30:40 by rcheong          ###   ########.fr       */
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
		ft_free_strarr((void **)data->map_det.file);
	if (data->map)
		ft_free_strarr((void **)data->map);
}

void	ft_free_img(t_img *img)
{
	if (img->addr)
		ft_free1(img->addr);
	if (img->path)
		ft_free1(img->path);
}

void	ft_free_img(t_data *data)
{
	ft_free_img(&data->e_img);
	ft_free_img(&data->s_img);
	ft_free_img(&data->n_img);
	ft_free_img(&data->w_img);
}

int	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->textures)
			ft_free_strarr((void **)data->textures);
		if (data->texture_pix)
			ft_free_strarr((void **)data->texture_pix);
		ft_free_textures(&data->texture_det);
		ft_free_img(data);
		ft_free_map(data);
	}
	return (EXIT_FAILURE);
}
