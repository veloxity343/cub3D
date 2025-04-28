#include "cub3d.h"

static int 	is_wall_hit(t_ray *ray, t_game *game);

/**
 * @brief DDA setup
 * @param side_dist Distance of player from edge * distance for one full grid unit.
 */
void setup_dda(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = ((ray->map.x + 1.0) - player->pos.x) * ray->delta_dist.x;
	}

	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = ((ray->map.y + 1.0) - player->pos.y) * ray->delta_dist.y;
	}
}

/**
 * @brief Loops and processes DDA steps
 * per side distance until a wall/boundary is hit.
 */
void do_dda(t_game *game, t_ray *ray)
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
		if (is_wall_hit(ray, game))
			break ;
	}
}

/**
 * @brief Ensure ray does not cast beyond map boundaries or walls.
 */
static int is_wall_hit(t_ray *ray, t_game *game)
{
	return (ray->map.y < 0.0 ||
			ray->map.y >= game->map_info.h ||
			ray->map.x < 0.0 ||
			ray->map.x >= game->map_info.w ||
			game->map[ray->map.y][ray->map.x] != '0');
}
