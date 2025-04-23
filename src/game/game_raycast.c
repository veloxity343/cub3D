/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:19:12 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/23 21:35:35 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initialises raycasting parameters for a given pixel.
 * @param x The x-coordinate of the pixel.
 * @param ray Pointer to the ray structure to initialise.
 * @param player Pointer to the player structure.
 * @details Sets up the camera position, direction, and other raycasting parameters
 * for the specified pixel on the screen.
 * - ray->cam_x: Camera x-coordinate in normalised device coordinates
 * - ray->dir: Direction vector based on player direction and camera x-coordinate (FOV)
 * - ray->map: Map coordinates of the ray's starting position
 * - ray->delta_dist: Pythagorean distance to the next grid line
 */
static void	init_raycast_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->cam_x = 2 * x / (double)WIN_W - 1;
	ray->dir.x = player->dir_t.x + player->plane.x * ray->cam_x;
	ray->dir.y = player->dir_t.y + player->plane.y * ray->cam_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
}

/**
 * @brief Sets up the DDA parameters for raycasting.
 * @param ray Pointer to the ray structure.
 * @param player Pointer to the player structure.
 * @details Determines the step direction and initial side distance based on the ray's direction
 * and the player's position. This is crucial for determining which grid cell the ray will hit first.
 * Both axes follow the same logic:
 * left: distance = current pos - current tile
 * right: distance = next tile - current pos
 * all multiplied by the delta (pythagorean) distance to get travel distance
 */
static void	set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y)
			* ray->delta_dist.y;
	}
}

/**
 * @brief Performs the DDA algorithm to find the wall hit by the ray.
 * @param game Pointer to the game structure.
 * @param ray Pointer to the ray structure.
 * @details Iteratively checks which side of the grid the ray hits first,
 * updating the map coordinates and side distances accordingly.
 * Stops when a wall is hit or when the ray goes out of bounds.
 */
static void	start_dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (ray->map.y < 0.5 || ray->map.x < 0.5
			|| ray->map.y > game->map_info.h - 0.25
			|| ray->map.x > game->map_info.w - 1.25
			|| game->map[ray->map.y][ray->map.x] > '0')
			break ;
	}
}

/**
 * @brief Calculates the height of the line to be drawn based on the ray's distance.
 * @param ray Pointer to the ray structure.
 * @param game Pointer to the game structure.
 * @param player Pointer to the player structure.
 * @details Computes the height of the line to be drawn on the screen based on
 * the distance to the wall hit by the ray. Also calculates the start and end
 * points for drawing the line, and determines the wall's x-coordinate for texture mapping.
 */
static void	calc_line_h(t_ray *ray, t_game *game, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	ray->line_h = (int)(game->win_h / ray->wall_dist);
	ray->start = fmax(0, (game->win_h - ray->line_h) / 2);
	ray->end = fmin(game->win_h - 1, (game->win_h + ray->line_h) / 2);
	if (ray->side == 0)
		ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}

/**
 * @brief Performs raycasting for the entire screen.
 * @param player Pointer to the player structure.
 * @param game Pointer to the game structure.
 * @return SUCCESS on success, otherwise an error code.
 * @details Iterates through each pixel on the screen, initialises raycasting
 * parameters, performs DDA, calculates line height, and updates texture pixels.
 */
int	raycast(t_player *player, t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < game->win_w)
	{
		init_raycast_info(x, &ray, player);
		set_dda(&ray, player);
		start_dda(game, &ray);
		calc_line_h(&ray, game, player);
		update_tex_px(game, &game->tex_info, &ray, x);
		x++;
	}
	return (SUCCESS);
}
