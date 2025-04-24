/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:51:56 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/24 16:01:14 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Reads the file line by line and returns an array of strings.
 * @param path The path to the file.
 * @return A strings containing the file contents.
 * @details This function opens the file, reads it line by line,
 * and stores each line in a strings.
 */
char	*read_file(char *path)
{
	int		fd;
	char	*temp;
	char	*readd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
	}
	temp = get_next_line(fd);
	readd = ft_calloc(1, 1);
	while (temp)
	{
		readd = ft_strjoin_free(readd, temp);
		ft_free1(temp);
		temp = get_next_line(fd);
	}
	return (readd);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (!arr || !arr[0])
		return ;
	while (arr[++i])
		free(arr[i]);
	if (arr)
		free(arr);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/**
 * @brief Duplicates an array of strings.
 * @param arr The array of strings to duplicate.
 * @return A new array of strings that is a duplicate of the original.
 * @details This function allocates memory for a new array and copies
 * each string from the original array into the new one.
 */
char	**ft_arrdup(char **arr)
{
	int		i;
	char	**new;

	i = -1;
	if (!arr || !arr[0])
		return (NULL);
	new = malloc((ft_arrlen(arr) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (arr[++i])
	{
		new[i] = ft_strdup(arr[i]);
		if (!new[i])
		{
			free_arr(new);
			return (NULL);
		}
	}
	new[i] = NULL;
	return (new);
}

/**
 * @brief Joins two strings and frees the first one.
 * @param s1 The first string to join.
 * @param s2 The second string to join.
 * @return A new string that is the result of the join.
 * @details This function concatenates two strings and frees the first.
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	new = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (new);
}
