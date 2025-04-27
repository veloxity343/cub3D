#include "cub3d.h"

static void process_dda_step(t_ray *ray);
static int is_wall_hit(t_ray *ray, t_game *game);

void set_dda(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x) * ray->delta_dist.x;
	}

	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y) * ray->delta_dist.y;
	}
}

void start_dda(t_game *game, t_ray *ray)
{
	while (1)
	{
		process_dda_step(ray);
		if (is_wall_hit(ray, game))
			break;
	}
}

static void process_dda_step(t_ray *ray)
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
}

static int is_wall_hit(t_ray *ray, t_game *game)
{
	return (ray->map.y < 0.5 || ray->map.x < 0.5 ||
			ray->map.y > game->map_info.h - 0.25 ||
			ray->map.x > game->map_info.w - 1.25 ||
			game->map[ray->map.y][ray->map.x] > '0');
}
