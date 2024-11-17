/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:29:52 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/15 14:34:23 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Generic method to validate any type of file. Will validate 4 last
 * char in a file, verifying if the file is greater than 4 size.
 * @param file file name
 * @param c1 char 1 in sentence
 * @param c2 char 2 in sentence
 * @param c3 char 3 in sentence
 * @return boolean. Validate or not
 */
static bool	ft_valid_file_exit(char *file, char c1, char c2, char c3)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (file[len - 4] != '.' || file[len - 3] != c1 || file[len - 2] != c2
		|| file[len - 1] != c3)
		return (false);
	return (true);
}

bool	ft_valid_cub_file(char *file)
{
	return (ft_valid_file_ext(file, 'c', 'u', 'b'));
}

bool	ft_valid_file_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}
