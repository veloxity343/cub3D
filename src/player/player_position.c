/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:43 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:17:46 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	wall_collision(t_game *game, double x, double y)
{
	if (game->map[(int)y][(int)x] == '0'
		|| game->map[(int)y][(int)x] == 'D')
		return (1);
	return (0);
}

static int	valid_position(t_game *game, double x, double y)
{
	return (wall_collision(game, x, y));
}

int	validate_move(t_game *game, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (valid_position(game, new_x, game->player.pos.y))
	{
		game->player.pos.x = new_x;
		moved = 1;
	}
	if (valid_position(game, game->player.pos.x, new_y))
	{
		game->player.pos.y = new_y;
		moved = 1;
	}
	return (moved);
}
