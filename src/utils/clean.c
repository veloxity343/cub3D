/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:40:54 by rcheong           #+#    #+#             */
/*   Updated: 2025/02/05 20:55:59 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		ft_free2((void **)data->map_det.file);
	if (data->map)
		ft_free2((void **)data->map);
}

int	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->textures)
			ft_free2((void **)data->textures);
		if (data->texture_pix)
			ft_free2((void **)data->texture_pix);
		ft_free_textures(&data->texture_det);
		ft_free_map(data);
	}
	return (EXIT_FAILURE);
}
