/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:56:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/02/16 15:57:02 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_valid_texture(t_texture_det *text)
{
	if (!text->north || !text->south || !text->east || !text->west)
		return (ft_error_msg(ERR_TEXT_MAP, 12));
	if (!text->ceiling || !text->floor)
		return (ft_error_msg(ERR_TEXT_COL, 13));
	if (!ft_val_file_path(text->north) || !ft_val_file_path(text->south)
		|| !ft_val_file_path(text->east) || !ft_val_file_path(text->west))
		return (ft_error_msg(ERR_TEXT_PATH, 14));
	if (ft_valid_rgb(text->ceiling) == false || ft_valid_rgb(text->floor) == false)
		return (ft_error_msg(ERR_RGB_VAL, 15));
	text->hex_ceiling = ft_rgb_to_hex(text->ceiling);
	text->hex_floor = ft_rgb_to_hex(text->floor);
	return (0);
}

/**
 * @brief Verify if RGB value from file, is between 0 and 255
 * @param rgb_val RGB Value
 * @return Boolean
 */
static bool	ft_valid_rgb(int *rgb_val)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb_val[i] < 0 || rgb_val[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Convert the RGB Color in file to hexadecimal color
 * @param rgb Array of int representing RGB Color
 * @return unsigned long
 */
static unsigned long	ft_rgb_to_hex(int *rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
