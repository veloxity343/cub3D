#include "cub3d.h"

/**
 * @brief Will destroy all mlx windows and free all data.
 * @param data Data structure
 * @return int
 */
int	close_hook(t_data *d)
{
	mlx_destroy_image(d->window.mlx, d->window.screen.img);
	mlx_destroy_window(d->window.mlx, d->window.win);
	mlx_destroy_display(d->window.mlx);
	free_data(d);
	free(d->window.mlx);
	exit(SUCCESS);
}

/**
 * @brief Handle all key press used in game.
 * @param keycode Key code pressed
 * @param data Data structure
 * @return int
 */
int	key_hook(int key, t_data *d)
{
	if (key == XK_Escape)
		close_hook(d);
	if (key == XK_w)
		move(d, d->player.dir_x, d->player.dir_y);
	if (key == XK_s)
		move(d, -d->player.dir_x, -d->player.dir_y);
	if (key == XK_a)
		move(d, -d->player.plane_x, -d->player.plane_y);
	if (key == XK_d)
		move(d, d->player.plane_x, d->player.plane_y);
	if (key == XK_Left)
	{
		rotate(&d->player.dir_x, &d->player.dir_y, -ROTSPEED);
		rotate(&d->player.plane_x, &d->player.plane_y, -ROTSPEED);
	}
	if (key == XK_Right)
	{
		rotate(&d->player.dir_x, &d->player.dir_y, ROTSPEED);
		rotate(&d->player.plane_x, &d->player.plane_y, ROTSPEED);
	}
	debug(d);
	return (SUCCESS);
}

int	starting_game(t_data *d)
{
	mlx_hook(d->window.win, DestroyNotify, StructureNotifyMask, close_hook, d);
	mlx_hook(d->window.win, KeyPress, KeyPressMask, key_hook, d);
	mlx_loop_hook(d->window.mlx, render_images, d);
	return (SUCCESS);
}
