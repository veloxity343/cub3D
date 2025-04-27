#include "cub3d.h"

static void calc_wall_distance(t_ray *ray);
static void calc_line_height(t_ray *ray, t_game *game);
static void calc_wall_x(t_ray *ray, t_player *player);

void calc_wall_height(t_ray *ray, t_game *game, t_player *player)
{
	calc_wall_distance(ray);
	calc_line_height(ray, game);
	calc_wall_x(ray, player);
}

static void calc_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y);
}

static void calc_line_height(t_ray *ray, t_game *game)
{
	ray->line_h = (int)(game->win_h / ray->wall_dist);
	ray->start = fmax(0, (game->win_h - ray->line_h) / 2);
	ray->end = fmin(game->win_h - 1, (game->win_h + ray->line_h) / 2);
}

static void calc_wall_x(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_x = player->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}
