#include "cub3d.h"

static void	init_raycast_info(int pixel_x, t_ray *ray, t_player *player);
static void	calc_ray_direction(t_ray *ray, t_player *player);
static void	calc_map_coords(t_ray *ray, t_player *player);
static void	calc_delta_dist(t_ray *ray);

/**
 * @brief Raycasting function to calculate the ray's path and render the scene.
 * @param pixel_x Iterate through each pixel of the screen left to right.
 */
int	raycast(t_player *player, t_game *game)
{
	t_ray	ray;
	int		pixel_x;

	pixel_x = 0;
	ray = game->ray;
	while (pixel_x < game->win_w)
	{
		init_raycast_info(pixel_x, &ray, player);
		setup_dda(&ray, player);
		do_dda(game, &ray);
		calc_wall_height(&ray, game, player);
		engine_loop(game, &game->tex_info, &ray, pixel_x);
		pixel_x++;
	}
	return (SUCCESS);
}

/**
 * @brief Initialises the raycasting information for a given pixel.
 * @param cam_x The x-coordinate of the pixel on the screen between -1 to 1.
 * @details Ratio of horizontal pixel to screen width set between -1 and 1.
 */
static void	init_raycast_info(int pixel_x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->cam_x = 2 * (pixel_x / (double)WIN_W) - 1;
	calc_ray_direction(ray, player);
	calc_map_coords(ray, player);
	calc_delta_dist(ray);
}

/**
 * @brief Corrected ray direction from plane instead of player for linearity.
 * @param dir ray = player direction + plane vector
 * @param dir_t Direction based on player.
 * @param plane*cam +/- Plane vector based on horizontal cam.
 */
static void	calc_ray_direction(t_ray *ray, t_player *player)
{
	ray->dir.x = player->dir_t.x + (player->plane.x * ray->cam_x);
	ray->dir.y = player->dir_t.y + (player->plane.y * ray->cam_x);
}

static void	calc_map_coords(t_ray *ray, t_player *player)
{
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
}

/**
 * @brief Calculate the distance for a ray to traverse in x/y grid units.
 * @param delta_dist Equate sqrt(Δx² + Δy²)
 */
static void	calc_delta_dist(t_ray *ray)
{
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
}
