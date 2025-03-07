/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:06:12 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/14 11:50:59 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char	*ft_get_err_msg_general(t_err error)
{
	if (error == ERR_ARGS)
		return ("usage: ./cub3D <map_path/map.cub>");
	else if (error == ERR_MALC)
		return ("failed to allocate memory.");
	else if (error == ERR_CUB)
		return ("expected .cub file.");
	return (NULL);
}

const char	*ft_get_err_msg_map(t_err error)
{
	if (error == ERR_MAP)
		return ("map not found in file.");
	else if (error == ERR_MAP7)
		return ("invalid map specifications.");
	else if (error == ERR_MAP8)
		return ("map not surrounded by walls.");
	else if (error == ERR_MAP_LAST)
		return ("map must to be the last element in file.");
	else if (error == ERR_MAP_DIR)
		return ("map with no player direction set.");
	else if (error == ERR_MAP9)
		return ("map with invalid character.");
	else if (error == ERR_MAP_CHAR)
		return ("invalid character in map.");
	else if (error == ERR_SING_PLAYER)
		return ("only one player allowed.");
	else if (error == ERR_PLA_POS)
		return ("invalid player position.");
	return (NULL);
}

const char	*ft_get_err_msg_graphics(t_err error)
{
	if (error == ERR_TEXT)
		return ("invalid texture pattern.");
	else if (error == ERR_TEXT_MAP)
		return ("texture not found in file.");
	else if (error == ERR_TEXT_COL)
		return ("color not found in file.");
	else if (error == ERR_TEXT_PATH)
		return ("invalid path.");
	else if (error == ERR_RGB)
		return ("invalid RGB color format to floor/ceiling.");
	else if (error == ERR_RGB_VAL)
		return ("invalid RGB value passed by parameter.");
	return (NULL);
}

const char	*ft_get_err_msg_mlx(t_err error)
{
	if (error == ERR_MLX_IMG)
		return ("failed to initialize MLX new image.");
	else if (error == ERR_MLX_WIN)
		return ("failed to initialize MLX new window.");
	else if (error == ERR_MLX_INIT)
		return ("failed to initialize MLX framework.");
	return (NULL);
}

const char	*ft_get_err_msg(t_err error)
{
	const char	*message;

	message = ft_get_err_msg_general(error);
	if (message)
		return (message);
	message = ft_get_err_msg_map(error);
	if (message)
		return (message);
	message = ft_get_err_msg_graphics(error);
	if (message)
		return (message);
	message = ft_get_err_msg_mlx(error);
	if (message)
		return (message);
	return ("unknown.");
}
