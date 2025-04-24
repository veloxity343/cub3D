/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:20 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/24 13:32:24 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
for macos using
void	clean(t_game *game, int code)
{
	if (game)
	{
		if (game->win && game->mlx)
			mlx_destroy_window(game->mlx, game->win);
#ifdef __linux__
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			mlx_loop_end(game->mlx);
			free(game->mlx);
		}
#endif
		free_game(game);
	}
	exit(code);
}
*/

void	clean(t_game *game, int code)
{
	if (game)
	{
		if (game->win && game->mlx)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			mlx_loop_end(game->mlx);
			free(game->mlx);
		}
		free_game(game);
	}
	exit(code);
}

/**
 * @brief Cleans up the game resources and exits the program.
 * @param game The game structure to clean up.
 * @return 0 on success.
 * @details This function cleans up the game MLX resources and exits the program
 * with a success code.
 */
int	quit(t_game *game)
{
	clean(game, 0);
	return (0);
}
