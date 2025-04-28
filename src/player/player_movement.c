/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:49 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/28 20:23:11 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_player_dir(t_game *game, double dir_x, double dir_y);
static int	valid_position(t_game *game, double x, double y);

/**
 * @brief Moves the player based on the input direction.
 * @param game The game structure.
 * @return The number of moves made.
 * @details This function checks the player's movement direction
 * and updates the player's position accordingly, also handling
 * rotation.
 */
int	move_player(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move.y == 1)
		moved += move_player_dir(game, game->player.dir_t.x,
				game->player.dir_t.y);
	if (game->player.move.y == -1)
		moved += move_player_dir(game, -game->player.dir_t.x,
				-game->player.dir_t.y);
	if (game->player.move.x == -1)
		moved += move_player_dir(game, game->player.dir_t.y,
				-game->player.dir_t.x);
	if (game->player.move.x == 1)
		moved += move_player_dir(game, -game->player.dir_t.y,
				game->player.dir_t.x);
	if (game->player.rotate)
		moved += rotate_player(game, game->player.rotate);
	return (moved);
}

/**
 * @brief This function calculates the new position of the player
 * based on the direction vector and checks if the move is valid.
 */
static int	move_player_dir(t_game *game, double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + dir_x * S_MOVE;
	new_y = game->player.pos.y + dir_y * S_MOVE;
	return (validate_move(game, new_x, new_y));
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

static int	valid_position(t_game *game, double x, double y)
{
	if (game->map[(int)y][(int)x] == '0')
		return (1);
	return (0);
}
