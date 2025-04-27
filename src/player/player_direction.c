/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:59 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/23 21:07:01 by rcheong          ###   ########.fr       */
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

/**
 * @brief Initialises the player's direction and plane.
 * @param game The game structure.
 * @details This function sets the player's direction and plane
 * based on the specified direction (N, S, E, W). 
 * Left to right, top to bottom logic (so N is (0, -1) but E is (1, 0)).
 * 0.66 is used to set the plane direction to be perpendicular to the player's
 * direction.
 */
void	init_player_dir(t_game *game)
{
	double	plane_size;

	plane_size = tan((FOV) * M_PI / 360.0);
	set_player_dir(&game->player, 'N', (t_dir_d){0, -1}, (t_dir_d){plane_size, 0});
	set_player_dir(&game->player, 'S', (t_dir_d){0, 1}, (t_dir_d){-plane_size, 0});
	set_player_dir(&game->player, 'E', (t_dir_d){1, 0}, (t_dir_d){0, plane_size});
	set_player_dir(&game->player, 'W', (t_dir_d){-1, 0}, (t_dir_d){0, -plane_size});
}
