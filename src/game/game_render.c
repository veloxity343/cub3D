/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:19:07 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 18:19:09 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_img_px(t_game *game, t_img *img, int x, int y)
{
	if (game->tex_px[y][x] > 0)
		set_img_px(img, x, y, game->tex_px[y][x]);
	else if (y < game->win_h / 2)
		set_img_px(img, x, y, game->tex_info.hex_c);
	else if (y < game->win_h - 1)
		set_img_px(img, x, y, game->tex_info.hex_f);
}

static void	render_frame(t_game *game)
{
	t_img	img;
	int		x;
	int		y;

	y = 0;
	img.img = NULL;
	init_mlx_img(game, &img, game->win_w, game->win_h);
	while (y < game->win_h)
	{
		x = 0;
		while (x < game->win_w)
			set_frame_img_px(game, &img, x++, y);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_destroy_image(game->mlx, img.img);
}

void	set_img_px(t_img *img, int x, int y, int colour)
{
	img->adr[y * (img->size_line / 4) + x] = colour;
}

void	render_raycast(t_game *game)
{
	init_tex_px(game);
	init_ray(&game->ray);
	raycast(&game->player, game);
	render_frame(game);
}

int	render_img(t_game *game)
{
	game->player.moved += move_player(game);
	if (game->player.moved == 0)
		return (0);
	render_raycast(game);
	return (0);
}
