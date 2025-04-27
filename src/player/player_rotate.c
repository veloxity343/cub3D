/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:36 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/23 21:16:30 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Rotation vector is calculated using the formula:
 * x' = x * cos(angle) - y * sin(angle)
 * y' = x * sin(angle) + y * cos(angle)
 */
static void	rotate_vector(double *x, double *y, double angle)
{
	double	tmp_x;

	tmp_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = tmp_x * sin(angle) + *y * cos(angle);
}

/**
 * @brief Rotates the player's direction and plane.
 * @param game The game structure.
 * @param rotate_dir The direction to rotate (1 for right, -1 for left).
 * @return 1 if successful, 0 otherwise.
 * @details This function rotates the player's direction and plane
 * based on the specified rotation direction. The rotation speed is
 * defined by S_ROTATE.
 */
int	rotate_player(t_game *game, double rotate_dir)
{
	double	angle;

	angle = S_ROTATE * rotate_dir;
	rotate_vector(&game->player.dir_t.x, &game->player.dir_t.y, angle);
	rotate_vector(&game->player.plane.x, &game->player.plane.y, angle);
	return (1);
}
