/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:20 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 10:12:21 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean(t_game *game, int code)
{
	if (game)
	{
		if (game->win && game->mlx)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
#ifdef __linux__
			mlx_destroy_display(game->mlx);
			mlx_loop_end(game->mlx);
			free(game->mlx);
#endif
		}
		free_game(game);
	}
	exit(code);
}

int	quit(t_game *game)
{
	clean(game, 0);
	return (0);
}
