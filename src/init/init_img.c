/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:18:44 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/28 10:32:57 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*img_from_xpm(t_game *game, char *path);

void	init_pattern(t_game *game)
{
	game->tex = ft_calloc(5, sizeof * game->tex);
	if (!game->tex)
		clean(game, error_msg("img: init_pattern", MALLOC, FAILURE, 0));
	game->tex[NORTH] = img_from_xpm(game, game->tex_info.north);
	game->tex[SOUTH] = img_from_xpm(game, game->tex_info.south);
	game->tex[EAST] = img_from_xpm(game, game->tex_info.east);
	game->tex[WEST] = img_from_xpm(game, game->tex_info.west);
}

static int	*img_from_xpm(t_game *game, char *path)
{
	t_img	tmp;
	int		*buff;

	init_mlx_img_tex(game, &tmp, path);
	buff = ft_calloc(game->tex_info.size * game->tex_info.size, sizeof * buff);
	if (!buff)
		clean(game, error_msg("img: img_from_xpm", MALLOC, FAILURE, 0));
	ft_memcpy(buff, tmp.adr,
		game->tex_info.size * game->tex_info.size * sizeof * buff);
	mlx_destroy_image(game->mlx, tmp.img);
	return (buff);
}

void init_tex_px(t_game *game)
{
	int i;

	i = 0;
	free_tab((void **)game->tex_px);
	game->tex_px = ft_calloc(game->win_h + 1, sizeof(*game->tex_px));
	if (!game->tex_px)
		clean(game, error_msg("tex: init_tex_px", MALLOC, 1, 0));
	while (i < game->win_h)
	{
		game->tex_px[i] = ft_calloc(game->win_w + 1, sizeof(*game->tex_px));
		if (!game->tex_px[i])
			clean(game, error_msg("tex: init_tex_px", MALLOC, 1, 0));
		i++;
	}
}

void	init_tex(t_tex *tex)
{
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->east = NULL;
	tex->size = SIZE_TEX;
	tex->floor = 0;
	tex->ceiling = 0;
	tex->hex_f = 0x0;
	tex->hex_c = 0x0;
	tex->step = 0.0;
	tex->pos = 0.0;
	tex->dir.x = 0;
	tex->dir.y = 0;
}
