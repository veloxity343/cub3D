/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:31:11 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/26 17:07:35 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Will destroy all mlx windows and free all data.
 * @param data Data structure
 * @return int
 */
int	ft_close_hook(t_data *d)
{
	mlx_destroy_image(d->window.mlx, d->window.screen.img);
	mlx_destroy_window(d->window.mlx, d->window.win);
	mlx_destroy_display(d->window.mlx);
	ft_free_data(d);
	free(d->window.mlx);
	exit(SUCCESS);
}

/**
 * @brief Handle all key press used in game.
 * @param keycode Key code pressed
 * @param data Data structure
 * @return int
 */
int	ft_key_hook(int key, t_data *d)
{
	if (key == XK_Escape)
		ft_close_hook(d);
	if (key == XK_w)
		ft_move(d, d->player.dir_x, d->player.dir_y);
	if (key == XK_s)
		ft_move(d, -d->player.dir_x, -d->player.dir_y);
	if (key == XK_a)
		ft_move(d, -d->player.plane_x, -d->player.plane_y);
	if (key == XK_d)
		ft_move(d, d->player.plane_x, d->player.plane_y);
	if (key == XK_Left)
	{
		ft_rotate(&d->player.dir_x, &d->player.dir_y, -ROTSPEED);
		ft_rotate(&d->player.plane_x, &d->player.plane_y, -ROTSPEED);
	}
	if (key == XK_Right)
	{
		ft_rotate(&d->player.dir_x, &d->player.dir_y, ROTSPEED);
		ft_rotate(&d->player.plane_x, &d->player.plane_y, ROTSPEED);
	}
	return (SUCCESS);
}

int	ft_starting_game(t_data *d)
{
	mlx_hook(d->window.win, DestroyNotify, StructureNotifyMask, ft_close_hook, d);
	mlx_hook(d->window.win, KeyPress, KeyPressMask, ft_key_hook, d);
	mlx_loop_hook(d->window.mlx, ft_render_images, d);
	return (SUCCESS);
}
