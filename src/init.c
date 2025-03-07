/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:29:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/02/02 22:19:56 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Handle the number of lines of the file.
 * @param path Path of the file
 * @return int Number of lines of the file
 */
static int	ft_lines_file(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_exit_cube(NULL, ft_error_msg(strerror(errno), 3));
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			ft_free1(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

/**
 * @brief Initialize variables passed by ref. Just to avoid norminette:
 * functions huge
 * @param row 'row' variable
 * @param i 'i' variable
 * @param coll 'coll' variable
 */
static void	ft_init_load_map_var(int *row, int *i, int *coll)
{
	*row = 0;
	*i = 0;
	*coll = 0;
}

/**
 * @brief Responsible to read the path, by GNL, and populate the map matrix
 * @param data Data Structure by ref
 */
static void	ft_load_map(t_data *data)
{
	int		coll;
	int		i;
	int		row;
	char	*line;

	ft_init_load_map_var(&row, &i, &coll);
	line = get_next_line(data->map_det.fd);
	while (line != NULL)
	{
		data->map_det.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map_det.file[row])
		{
			ft_error_msg(ERR_MALC, 2);
			return (ft_free_strarr(data->map_det.file));
		}
		while (line[i] != '\0')
			data->map_det.file[row][coll++] = line[i++];
		data->map_det.file[row++][coll] = '\0';
		coll = 0;
		i = 0;
		ft_free1(line);
		line = get_next_line(data->map_det.fd);
	}
	data->map_det.file[row] = NULL;
}

void	ft_init_map_handler(t_data *data, char *path)
{
	data->map_det.lines_file = ft_lines_file(path);
	data->map_det.path = path;
	data->map_det.file = ft_calloc(data->map_det.lines_file + 1,
			sizeof(char *));
	if (!data->map_det.file)
	{
		ft_error_msg(ERR_MALC, 2);
		return ;
	}
	data->map_det.fd = open(path, O_RDONLY);
	if (data->map_det.fd < 0)
		ft_exit_cube(data, ft_error_msg(strerror(errno), 3));
	else
	{
		ft_load_map(data);
		close(data->map_det.fd);
	}
}
