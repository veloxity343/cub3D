#include "cub3d.h"

static void init_raycast_info(int pixel_x, t_ray *ray, t_player *player);
static void calc_ray_direction(t_ray *ray, t_player *player);
static void calc_map_coords(t_ray *ray, t_player *player);
static void calc_delta_dist(t_ray *ray);

int raycast(t_player *player, t_game *game)
{
	t_ray ray;
	int pixel_x;

	pixel_x = 0;
	ray = game->ray;
	while (pixel_x < game->win_w)
	{
		init_raycast_info(pixel_x, &ray, player);
		set_dda(&ray, player);
		start_dda(game, &ray);
		calc_wall_height(&ray, game, player);
		engine_loop(game, &game->tex_info, &ray, pixel_x);
		pixel_x++;
	}
	return (SUCCESS);
}

static void init_raycast_info(int pixel_x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->cam_x = 2 * (pixel_x / (double)WIN_W) - 1;
	calc_ray_direction(ray, player);
	calc_map_coords(ray, player);
	calc_delta_dist(ray);
}

static void calc_ray_direction(t_ray *ray, t_player *player)
{
	ray->dir.x = player->dir_t.x + (player->plane.x * ray->cam_x);
	ray->dir.y = player->dir_t.y + (player->plane.y * ray->cam_x);
}

static void calc_map_coords(t_ray *ray, t_player *player)
{
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
}

static void calc_delta_dist(t_ray *ray)
{
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
}
