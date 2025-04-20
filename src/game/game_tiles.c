/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:55 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:18:58 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_tile_px(t_framebuffer *m, int x, int y, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->tile_size)
	{
		j = 0;
		while (j < m->tile_size)
			set_img_px(m->img, x + j++, i + y, colour);
		i++;
	}
}

static void	gen_tile(t_framebuffer *m, int x, int y)
{
	int					tile;
	static const int	colours[256] = {
	['P'] = COL_USR, ['1'] = COL_WALL,
	['0'] = COL_FLOOR, [' '] = COL_SPACE,
	};

	tile = m->map[y][x];
	if (colours[tile])
		set_tile_px(m, x * m->tile_size, y * m->tile_size, colours[tile]);
}

static void	set_border_img_px(t_framebuffer *m, int colour)
{
	int	x;
	int	y;
	int	size;

	y = 0;
	size = MM_PX + m->tile_size;
	while (y < size)
	{
		x = 0;
		while (x <= size)
		{
			if (x < 5 || x > size - 5 || y < 5 || y > size - 5)
				set_img_px(m->img, x, y, colour);
			x++;
		}
		y++;
	}
}

static void	gen_framebuffer(t_framebuffer *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->size)
	{
		x = 0;
		while (x < m->size)
		{
			if (!m->map[y] || !m->map[y][x])
				break ;
			gen_tile(m, x, y);
			x++;
		}
		y++;
	}
	set_border_img_px(m, 0x404040);
}

void	render_tiles(t_game *game, t_framebuffer *m)
{
	int	img_size;

	img_size = MM_PX + m->tile_size;
	init_mlx_img(game, &game->framebuffer, img_size, img_size);
	gen_framebuffer(m);
	mlx_put_image_to_window(game->mlx, game->win, game->framebuffer.img,
		m->tile_size, game->win_h - (MM_PX + m->tile_size * 2));
	mlx_destroy_image(game->mlx, game->framebuffer.img);
}
