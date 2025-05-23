/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:05 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/29 19:18:28 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_dir(char *arg);
static int	has_ext(char *arg, char *ext);

/**
 * @brief Validates the file permissions, path and extension.
 * @param arg The file path to validate.
 * @param cub Flag to check for .cub or .xpm extension.
 * @return SUCCESS if valid, FAILURE otherwise.
 * @details Checks if the file is a directory, if it can be opened,
 * and if it has the correct extension.
 */
int	validate_file(char *arg, int cub)
{
	int	fd;

	if (is_dir(arg))
		return (error_msg(arg, FILE_IS_DIR, FAILURE, 0));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (error_msg(arg, errno, FAILURE, 1));
	close(fd);
	if (cub && !has_ext(arg, ".cub"))
		return (error_msg(arg, FILE_NOT_CUB, FAILURE, 0));
	return (SUCCESS);
}

static int	is_dir(char *arg)
{
	int	fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), 1);
	return (0);
}

static int	has_ext(char *arg, char *ext)
{
	size_t	len;
	size_t	ext_len;

	len = ft_strlen(arg);
	ext_len = ft_strlen(ext);
	if (len < ext_len)
		return (0);
	return (ft_strncmp(arg + len - ext_len, ext, ext_len) == 0);
}
