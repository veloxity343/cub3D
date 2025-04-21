/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:49 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 20:53:04 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->adr = NULL;
	img->px_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_ray(t_ray *ray)
{
	ray->cam_x = 0;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->map.x = 0;
	ray->map.y = 0;
	ray->step.x = 0;
	ray->step.y = 0;
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = 0;
	ray->delta_dist.y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_h = 0;
	ray->start = 0;
	ray->end = 0;
}

static void	init_map(t_map *map_info)
{
	map_info->path = NULL;
	map_info->file = NULL;
	map_info->fd = 0;
	map_info->line = 0;
	map_info->h = 0;
	map_info->w = 0;
	map_info->eom = 0;
}

static void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos.x = 0.0;
	player->pos.y = 0.0;
	player->dir_t.x = 0.0;
	player->dir_t.y = 0.0;
	player->plane.x = 0.0;
	player->plane.y = 0.0;
	player->moved = 0;
	player->move.x = 0;
	player->move.y = 0;
	player->rotate = 0;
}

void	init_game(t_game *game)
{
	game->win_h = WIN_H;
	game->win_w = WIN_W;
	game->win = NULL;
	game->mlx = NULL;
	game->map = NULL;
	game->cub_file = NULL;
	game->tex_px = NULL;
	game->tex = NULL;
	init_player(&game->player);
	init_tex(&game->tex_info);
	init_map(&game->map_info);
	init_img_clean(&game->framebuffer);
}
