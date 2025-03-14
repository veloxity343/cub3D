/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:34:19 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/14 18:07:03 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (ft_is_valid_pos_in_map(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (ft_is_valid_pos_in_map(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

/**
 * @brief This method will calculate if the axis X and Y keep inside the
 * map width and height. Will return true if is inside. false if is outside.
 * It will handle the limits player in map surrounded by '1's.
 * @hint: We must to check with fractions (0.25 and 1.25 for the speed mult.)
 * Without this, the player 'keep going' until fuck with map (explode hit wall)
 * @param data Data Structure
 * @param x axis X
 * @param y axis Y
 * @return boolean
 */
static bool	ft_is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map_det.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->map_det.height - 0.25)
		return (false);
	return (true);
}
