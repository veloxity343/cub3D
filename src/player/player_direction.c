/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:59 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 23:27:22 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_dir(t_player *player, char dir, t_dir_d dir_t, t_dir_d plane)
{
	if (player->dir == dir)
	{
		player->dir_t.x = dir_t.x;
		player->dir_t.y = dir_t.y;
		player->plane.x = plane.x;
		player->plane.y = plane.y;
	}
}

void	init_player_dir(t_game *game)
{
	set_player_dir(&game->player, 'N', (t_dir_d){0, -1}, (t_dir_d){0.66, 0});
	set_player_dir(&game->player, 'S', (t_dir_d){0, 1}, (t_dir_d){-0.66, 0});
	set_player_dir(&game->player, 'E', (t_dir_d){1, 0}, (t_dir_d){0, 0.66});
	set_player_dir(&game->player, 'W', (t_dir_d){-1, 0}, (t_dir_d){0, -0.66});
}
