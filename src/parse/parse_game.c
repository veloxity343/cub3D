/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:18 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:18:20 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_lines(char *path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg(path, errno, errno, 1));
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static void	fill_tab(t_game *game)
{
	char	*line;
	int		row;

	row = 0;
	line = get_next_line(game->map_info.fd);
	while (line)
	{
		game->map_info.file[row] = ft_strdup(line);
		free(line);
		if (!game->map_info.file[row])
			return (error_msg("game: fill_tab", MALLOC, 0, 0),
				free_tab((void **)game->map_info.file));
		row++;
		line = get_next_line(game->map_info.fd);
	}
	game->map_info.file[row] = NULL;
}

void	parse_game(char *path, t_game *game)
{
	game->map_info.line = get_lines(path);
	if (game->map_info.line < 0)
		return ;
	game->map_info.path = path;
	game->map_info.file = ft_calloc(game->map_info.line + 1, sizeof(char *));
	if (!game->map_info.file)
		return ((void)error_msg("game: parse_game", MALLOC, 0, 0));
	game->map_info.fd = open(path, O_RDONLY);
	if (game->map_info.fd < 0)
		return (ft_putendl_fd("\e[31mError", 2), ft_putstr_fd("\e[31m", 2),
			ft_putstr_fd(strerror(errno), 2), ft_putstr_fd("\n\e[0m", 2));
	fill_tab(game);
	close(game->map_info.fd);
}
