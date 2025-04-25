/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:28:50 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/25 15:03:30 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned long	get(char *s_rgb)
{
	char			**temp;
	unsigned int	rgb[3];
 
	temp = ft_split(s_rgb, ',');
	rgb[0] = ft_atoi(temp[0]);
	rgb[1] = ft_atoi(temp[1]);
	rgb[2] = ft_atoi(temp[2]);
	ft_free_strarr(temp);
	if (rgb[0] < 256 && rgb[1] < 256 && rgb[2] < 256)
		return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	return (ULONG_MAX);
}

int	get_rgb(t_tex *ttx, char *target1, char *target2)
{
	if (!ft_strncmp(target1, "F ", 2))
	{
		ttx->hex_f = get(target1);
		ttx->hex_c = get(target2);
	}
	else
	{
		ttx->hex_c = get(target1);
		ttx->hex_f = get(target2);
	}
	if (ttx->hex_f == ULONG_MAX || ttx->hex_c == ULONG_MAX)
		return (1);
	return (0);
}

/**
 * @brief Checks if the RGB values are in the correct format.
 * @param rgb The RGB values to check.
 * @return 0 if valid, 1 if invalid.
 * @details This function checks if the RGB values are in the format
 * "R,G,B" and ensures that there are exactly 3 values separated by commas.
 */
int	check_rgb(char *rgb)
{
	int	i;
	int	nbr0_cm1[2];

	i = -1;
	nbr0_cm1[0] = 0;
	nbr0_cm1[1] = 0;
	if (ft_strchr(rgb, ' '))
		return (1);
	while (rgb[++i])
	{
		if (ft_isdigit(rgb[i]))
			nbr0_cm1[0]++;
		else if (rgb[i] == ',')
		{
			nbr0_cm1[1]++;
			nbr0_cm1[0] = 0;
		}
		else
			return (1);
		if (nbr0_cm1[1] == 3 || nbr0_cm1[0] == 4)
			return (1);
	}
	if (nbr0_cm1[1] != 2)
		return (1);
	return (0);
}

/**
 * @brief Validates the RGB values for floor and ceiling.
 * @param data The game data structure.
 * @param rgb The RGB values to validate.
 * @return 0 if valid, 1 if invalid.
 * @details This function checks if the RGB values are in the correct format
 * and within the valid range. It also checks if the floor and ceiling
 * colors are set correctly, then retrieves the RGB values.
 */
int	valid_rgb(t_game *data, char **rgb)
{
	if (!rgb[0] || !rgb[1])
		return (error_msg(NULL, COLOR_MISSING, 1, 0));
	if (ft_strncmp(rgb[0], "F ", 2) || ft_strncmp(rgb[1], "C ", 2))
		if (ft_strncmp(rgb[0], "C ", 2) || ft_strncmp(rgb[1], "F ", 2))
			return (error_msg(NULL, COLOR_MISSING, 1, 0));
	if (check_rgb(rgb[0] + 2) || check_rgb(rgb[1] + 2))
		return (error_msg(NULL, COLOR_FLOOR_CEILING, 1, 0));
	if (get_rgb(&data->tex_info, rgb[0] + 2, rgb[1] + 2))
		return (error_msg(NULL, COLOR_FLOOR_CEILING, 1, 0));
	return (0);
}
