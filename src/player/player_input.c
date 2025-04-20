/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:53 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:17:56 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_game *game)
{
	if (key == ESC)
		quit(game);
	else if (key == L_LEFT)
		game->player.rotate = -1;
	else if (key == L_RIGHT)
		game->player.rotate = 1;
	else if (key == UP)
		game->player.move.y = 1;
	else if (key == LEFT)
		game->player.move.x = -1;
	else if (key == DOWN)
		game->player.move.y = -1;
	else if (key == RIGHT)
		game->player.move.x = 1;
	return (0);
}

static int	key_release(int key, t_game *game)
{
	if (key == ESC)
		quit(game);
	else if (key == UP && game->player.move.y == 1)
		game->player.move.y = 0;
	else if (key == DOWN && game->player.move.y == -1)
		game->player.move.y = 0;
	else if (key == LEFT && game->player.move.x == -1)
		game->player.move.x += 1;
	else if (key == RIGHT && game->player.move.x == 1)
		game->player.move.x -= 1;
	else if (key == L_LEFT && game->player.rotate <= 1)
		game->player.rotate = 0;
	else if (key == L_RIGHT && game->player.rotate >= -1)
		game->player.rotate = 0;
	return (0);
}

void	get_input(t_game *game)
{
	mlx_hook(game->win, ClientMessage, NoEventMask, quit, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, key_release, game);
}
