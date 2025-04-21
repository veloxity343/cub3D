/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:49 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 21:21:15 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_player_dir(t_game *game, double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + dir_x * S_MOVE;
	new_y = game->player.pos.y + dir_y * S_MOVE;
	return (validate_move(game, new_x, new_y));
}

int	move_player(t_game *game)
{
	int	moved;

	moved = 0;
	if (game->player.move.y == 1)
		moved += move_player_dir(game, game->player.dir_t.x, \
			game->player.dir_t.y);
	if (game->player.move.y == -1)
		moved += move_player_dir(game, -game->player.dir_t.x, \
			-game->player.dir_t.y);
	if (game->player.move.x == -1)
		moved += move_player_dir(game, game->player.dir_t.y, \
			-game->player.dir_t.x);
	if (game->player.move.x == 1)
		moved += move_player_dir(game, -game->player.dir_t.y, \
			game->player.dir_t.x);
	if (game->player.rotate)
		moved += rotate_player(game, game->player.rotate);
	return (moved);
}
