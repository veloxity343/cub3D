/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:33:34 by rcheong           #+#    #+#             */
/*   Updated: 2025/02/16 14:33:35 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pos_is_valid(t_data *data, char **map)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map[i - 1]) < (size_t)j || ft_strlen(map[i + 1]) < (size_t)j)
		return (FAILURE);
	return (SUCCESS);
}

bool	is_map_sur_walls2(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (i > 0 && !data->map[i - 1][j] && data->map[i][j] != C_WALL)
				return (false);
			else if (i < data->map_det.height -1 && !data->map[i + 1][j]
					&& data->map[i][j] != C_WALL)
				return (false);
		}
	}
	return (true);
}
