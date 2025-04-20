/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:36 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:17:40 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_vector(double *x, double *y, double angle)
{
	double	tmp_x;

	tmp_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = tmp_x * sin(angle) + *y * cos(angle);
}

int	rotate_player(t_game *game, double rotate_dir)
{
	double	speed;

	speed = S_ROTATE * rotate_dir;
	rotate_vector(&game->player.dir_t.x, &game->player.dir_t.y, speed);
	rotate_vector(&game->player.plane.x, &game->player.plane.y, speed);
	return (1);
}
