#include "cub3d.h"

static void	get_tex_index(t_game *game, t_ray *ray);
static void	handle_tex_dir(t_ray *ray, t_tex *tex);
static void	init_tex_step_pos(t_ray *ray, t_tex *tex, t_game *game);
static void	process_wall_slice(t_game *game, t_tex *tex, int x, int y);

void	engine_loop(t_game *game, t_tex *tex, t_ray *ray, int x)
{
	int	y;

	get_tex_index(game, ray);
	handle_tex_dir(ray, tex);
	init_tex_step_pos(ray, tex, game);
	y = ray->start;
	while (y < ray->end)
	{
		process_wall_slice(game, tex, x, y);
		y++;
	}
}

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

/**
 * @brief Calculates where the ray hit the wall
 * 		 along the texture's width (X-axis).
 * @details Also flips the texture if the ray hits the wall
 * 		 from the opposite side.
 */
static void	handle_tex_dir(t_ray *ray, t_tex *tex)
{
	tex->dir.x = (int)(ray->tex_coord * tex->size);
	if ((ray->side == 0 && ray->dir.x < 0)
		|| (ray->side == 1 && ray->dir.y > 0))
		tex->dir.x = tex->size - tex->dir.x - 1;
}

/**
 * @brief Sets up how much to advance down
 * 		in the texture (Y-axis) per screen pixel for the current wall slice.
 * @details The texture is drawn from the top of the wall slice to the bottom.
 * Scales the texture to fit the wall slice height based on distance to the wall.
 * Finds texture position based on the wall slice's vertical position
 * 		from midpoint.
 */
static void	init_tex_step_pos(t_ray *ray, t_tex *tex, t_game *game)
{
	tex->step = (double)tex->size / ray->line_h;
	tex->pos = (ray->start - (game->win_h / 2) + (ray->line_h / 2)) * tex->step;
}

/**
 * @brief Loop to fetch texture colour for each pixel and draw.
 * @details Modulo operation to wrap around the texture's Y coordinate.
 * (sample from top to bottom of texture within texture bounds.)
 * Steps down to the next pixel in the wall slice.
 * Uses the texture's X and Y coordinates to fetch the pixel colour.
 */
static void	process_wall_slice(t_game *game, t_tex *tex, int x, int y)
{
	int	colour;

	tex->dir.y = (int)tex->pos & (tex->size - 1);
	tex->pos += tex->step;
	colour = game->tex[tex->index][tex->size * tex->dir.y + tex->dir.x];
	if (colour > 0)
		game->tex_px[y][x] = colour;
}
