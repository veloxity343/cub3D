/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:08 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:18:10 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	if (ft_strchr(" \t\r\n\v\f", c))
		return (FAILURE);
	else
		return (SUCCESS);
}

size_t	max_len(t_map *map, int i)
{
	size_t	len;
	size_t	max_len;

	max_len = ft_strlen(map->file[i]);
	while (map->file[++i])
	{
		len = ft_strlen(map->file[i]);
		if (len > max_len)
			max_len = len;
	}
	return (max_len);
}
