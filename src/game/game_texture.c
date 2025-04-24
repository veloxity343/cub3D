/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:19:00 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/24 13:29:44 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Determines the texture based on the ray's side and direction.
 * @param game Pointer to the game structure.
 * @param ray Pointer to the ray structure.
 * @details This function sets the texture index in the game structure based
 * on which side of the wall was hit by the ray.
 */
static void	get_tex_index(t_game *game, t_ray *ray)
{
	if (ray->side != 0)
	{
		if (ray->dir.y > 0)
			game->tex_info.index = SOUTH;
		else
			game->tex_info.index = NORTH;
	}
	else
	{
		if (ray->dir.x > 0)
			game->tex_info.index = EAST;
		else
			game->tex_info.index = WEST;
	}
}

void	init_tex_px(t_game *game)
{
	int	i;

	i = 0;
	free_tab((void **)game->tex_px);
	game->tex_px = ft_calloc(game->win_h + 1, sizeof(*game->tex_px));
	if (!game->tex_px)
		clean(game, error_msg("tex: init_tex_px", MALLOC, 1, 0));
	while (i < game->win_h)
	{
		game->tex_px[i] = ft_calloc(game->win_w + 1, sizeof(*game->tex_px));
		if (!game->tex_px[i])
			clean(game, error_msg("tex: init_tex_px", MALLOC, 1, 0));
		i++;
	}
}

/**
 * @brief   Updates the texture pixels for a vertical wall slice.
 * @param   game Pointer to the game state structure.
 * @param   tex  Pointer to the texture information structure.
 * @param   ray  Pointer to the raycasting data structure.
 * @param   x    Column position on the screen to update.
 * @details 
 * - Computes horizontal coordinate
 * - Horizontally flips the texture if 
 * 		ray hit from specific directions (prevent mirroring).
 * - Calculates vertical stepping (`tex->step`) to 
 * 		map texture rows to screen pixels.
 * - Computes initial texture Y position (`tex->pos`) based on screen alignment.
 * - Loops from `ray->start` to `ray->end`, for each screen pixel:
 *     - Computes corresponding Y coordinate in the texture (`tex->dir.y`).
 *     - Fetches color from texture using 
 * 		`tex->index`, `tex->dir.y`, and `tex->dir.x`.
 *     - Applies shadows to NORTH and EAST textures.
 *     - Writes colour to `game->tex_px[y][x]` if non-zero.
 */
void	update_tex_px(t_game *game, t_tex *tex, t_ray *ray, int x)
{
	int	y;
	int	colour;

	get_tex_index(game, ray);
	tex->dir.x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir.x < 0)
		|| (ray->side == 1 && ray->dir.y > 0))
		tex->dir.x = tex->size - tex->dir.x - 1;
	tex->step = (double)tex->size / ray->line_h;
	tex->pos = (ray->start - game->win_h / 2 + ray->line_h / 2) * tex->step;
	y = ray->start;
	while (y < ray->end)
	{
		tex->dir.y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		colour = game->tex[tex->index][tex->size * tex->dir.y + tex->dir.x];
		if (tex->index == NORTH || tex->index == EAST)
			colour = (colour >> 1) & 8355711;
		if (colour > 0)
			game->tex_px[y][x] = colour;
		y++;
	}
}
