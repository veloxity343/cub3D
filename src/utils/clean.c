/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:40:54 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/15 14:47:59 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Free the textures structure
 * @param texture Texture Structure
 */
static void	free_textures(t_texture *texture)
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
	if (data->map.fd > 0)
		close(data->map.fd);
	if (data->map.file)
		ft_free2((void **)data->map.file);
	if (data->map)
		ft_free2((void **)data->map);
}

int	ft_free_data(t_data *data)
{
	if (data)
	{
		if (data->textures)
			ft_free2((void **)data->textures);
		if (data->texture_pixels)
			ft_free2((void **)data->texture_pix);
		ft_free_textures(&data->texture);
		ft_free_map(data);
	}
	return (EXIT_FAILURE);
}
