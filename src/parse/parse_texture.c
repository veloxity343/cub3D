/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:13 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:18:16 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	contains_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	*parse_rgb(char **values)
{
	int	*rgb;
	int	i;

	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		return (error_msg("tex: parse_rgb", MALLOC, 0, 0), NULL);
	i = 0;
	while (i < 3)
	{
		rgb[i] = ft_atoi(values[i]);
		if (!contains_digit(values[i]) || rgb[i] == -1)
		{
			free(rgb);
			free_tab((void **)values);
			return (NULL);
		}
		i++;
	}
	free_tab((void **)values);
	return (rgb);
}

static int	*set_rgb(char *line)
{
	char	**convert;
	int		count;

	count = 0;
	convert = ft_split(line, ',');
	while (convert[count])
		count++;
	if (count != 3)
		return (free_tab((void **)convert), NULL);
	return (parse_rgb(convert));
}

int	parse_tex(t_game *game, t_tex *tex, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (error_msg(
				game->map_info.path, COLOR_FLOOR_CEILING, ERROR, 0));
	if (line[j] == 'C' && !tex->ceiling)
	{
		tex->ceiling = set_rgb(line + j + 1);
		if (!tex->ceiling)
			return (error_msg(game->map_info.path, COLOR_CEILING, ERROR, 0));
	}
	else if (line[j] == 'F' && !tex->floor)
	{
		tex->floor = set_rgb(line + j + 1);
		if (!tex->floor)
			return (error_msg(game->map_info.path, COLOR_FLOOR, ERROR, 0));
	}
	else
		return (error_msg(
				game->map_info.path, COLOR_FLOOR_CEILING, ERROR, 0));
	return (SUCCESS);
}
