/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:32 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 16:31:49 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx_img(t_game *game, t_img *img, int w, int h)
{
	init_img_clean(img);
	img->img = mlx_new_image(game->mlx, w, h);
	if (!img->img)
		clean(game, error_msg("mlx: init_img", MLX_IMG, FAILURE, 0));
	img->adr = (int *)mlx_get_data_addr(img->img, &img->px_bits,
			&img->size_line, &img->endian);
}

void	init_mlx_img_tex(t_game *game, t_img *img, char *path)
{
	init_img_clean(img);
	img->img = mlx_xpm_file_to_image(game->mlx, path, &game->tex_info.size,
			&game->tex_info.size);
	if (!img->img)
		clean(game, error_msg("mlx: init_texture_img", MLX_IMG, FAILURE, 0));
	img->adr = (int *)mlx_get_data_addr(img->img, &img->px_bits,
			&img->size_line, &img->endian);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		clean(game, error_msg("mlx: init_mlx", MLX_START, FAILURE, 0));
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, WIN_N);
	if (!game->win)
		clean(game, error_msg("mlx: init_mlx", MLX_WIN, FAILURE, 0));
}
