/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:16:38 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:16:41 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_rgb(int *rgb)
{
	if (rgb[0] < 0 || rgb[0] > 255
		|| rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		return (print_error_val(*rgb, TEX_RGB_VAL, FAILURE, 0));
	return (SUCCESS);
}

static unsigned long	rgb_hex(int *rgb_tab)
{
	return (((rgb_tab[0] & 0xff) << 16)
		| ((rgb_tab[1] & 0xff) << 8)
		| (rgb_tab[2] & 0xff));
}

int	validate_tex(t_tex *tex, t_game *game)
{
	if (!tex->north || !tex->south || !tex->west || !tex->east)
		return (error_msg(game->map_info.path, TEX_MISSING, FAILURE, 0));
	if (!tex->floor || !tex->ceiling)
		return (error_msg(game->map_info.path, COLOR_MISSING, FAILURE, 0));
	if (validate_file(tex->north, 0) == FAILURE
		|| validate_file(tex->south, 0) == FAILURE
		|| validate_file(tex->west, 0) == FAILURE
		|| validate_file(tex->east, 0) == FAILURE
		|| validate_rgb(tex->floor) == FAILURE
		|| validate_rgb(tex->ceiling) == FAILURE)
		return (FAILURE);
	tex->hex_f = rgb_hex(tex->floor);
	tex->hex_c = rgb_hex(tex->ceiling);
	return (SUCCESS);
}
