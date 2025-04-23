/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:43 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/23 12:19:59 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_position(t_game *game, double x, double y)
{
	if (game->map[(int)y][(int)x] == '0')
		return (1);
	return (0);
}

/**
 * @brief Validates the player's movement.
 * @param game The game structure.
 * @param new_x The new x-coordinate of the player.
 * @param new_y The new y-coordinate of the player.
 * @return 1 if the player moved, 0 otherwise.
 * @details This function checks if the new position is valid
 * (not clipping through walls) and updates the player's position
 * accordingly.
 */
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
