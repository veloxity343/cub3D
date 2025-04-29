#include "cub3d.h"

static void	calc_wall_distance(t_ray *ray);
static void	calc_line_height(t_ray *ray, t_game *game);
static void	calc_tex_coord(t_ray *ray, t_player *player);

void	calc_wall_height(t_ray *ray, t_game *game, t_player *player)
{
	calc_wall_distance(ray);
	calc_line_height(ray, game);
	calc_tex_coord(ray, player);
}

/**
 * @brief Calculate the perpendicular distance to the wall.
 * @param wall_dist Subtract delta to correct for the side hit.
 */
static void	calc_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->wall_dist = (ray->side_dist.y - ray->delta_dist.y);
}

/**
 * @brief Calculate the height of the wall line to draw.
 * @param line_h Ratio of the screen height to the wall distance.
 * @param start Top of the wall, scaled to the screen boundary (fmax)
 *	and centred.
 * @param end Bottom of the wall, scaled to the screen boundary (fmin)
 *	and centred.
 */
static void	calc_line_height(t_ray *ray, t_game *game)
{
	ray->line_h = (int)(game->win_h / ray->wall_dist);
	ray->start = fmax(0, (game->win_h - ray->line_h) / 2);
	ray->end = fmin(game->win_h - 1, (game->win_h + ray->line_h) / 2);
}

/**
 * @brief Calculate the texture coordinate for wall.
 * @param tex_coord Current player position + relative movement of ray.
 * @details Calculated using perpendicular distance to the wall.
 */
static void	calc_tex_coord(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->tex_coord = player->pos.y + ray->wall_dist * ray->dir.y;
	else
		ray->tex_coord = player->pos.x + ray->wall_dist * ray->dir.x;
	ray->tex_coord -= floor(ray->tex_coord);
}
