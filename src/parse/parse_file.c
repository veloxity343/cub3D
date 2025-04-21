/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:26 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 17:55:12 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_tex_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	i = 0;
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc((len - j + 1));
	if (!path)
		return (NULL);
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	fill_tex_direction(t_tex *tex, char *line, int j)
{
	char	*path;

	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (ERROR);
	path = get_tex_path(line, j + 2);
	if (!path)
		return (ERROR);
	if (line[j] == 'N' && line[j + 1] == 'O' && !tex->north)
		tex->north = path;
	else if (line[j] == 'S' && line[j + 1] == 'O' && !tex->south)
		tex->south = path;
	else if (line[j] == 'W' && line[j + 1] == 'E' && !tex->west)
		tex->west = path;
	else if (line[j] == 'E' && line[j + 1] == 'A' && !tex->east)
		tex->east = path;
	else
		return (free(path), path = NULL, ERROR);
	return (SUCCESS);
}

static int	skip_whitespaces(t_game *game, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isdigit(map[i][j]))
	{
		if (create_map(game, map, i) == FAILURE)
			return (error_msg(game->map_info.path, MAP_INVALID, FAILURE, 0));
		return (SUCCESS);
	}
	if (!ft_isprint(map[i][j]) || ft_isdigit(map[i][j]))
		return (CONTINUE);
	if (map[i][j + 1] && ft_isprint(map[i][j + 1]) && !ft_isdigit(map[i][j]))
	{
		if (fill_tex_direction(&game->tex_info, map[i], j) == ERROR)
			return (error_msg(game->map_info.path, TEX_INVALID, FAILURE, 0));
		return (BREAK);
	}
	if (parse_tex(game, &game->tex_info, map[i], j) == ERROR)
		return (FAILURE);
	return (BREAK);
}

int	parse_file(t_game *game, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = skip_whitespaces(game, map, i, j);
			if (ret == BREAK)
				break ;
			else if (ret != CONTINUE)
				return (ret);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
