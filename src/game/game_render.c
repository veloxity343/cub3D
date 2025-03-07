/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:26:03 by rcheong           #+#    #+#             */
/*   Updated: 2025/02/17 17:26:28 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief calculate the raycast for each pixel
 *
 * @param d data struct
 * @return int
 */
static int	calc_raycast(t_data *d)
{
	d->window.x = 0;
	while (d->window.x < WIDTH)
	{
		setup_raycast_info(d->window.x, &d->ray, &d->player);
		calc_dda(&d->ray, &d->player);
		perform_dda(d, &d->ray);
		calculate_line_height(&d->ray, &d->player);
		update_text_pixels(d, &d->texture_det, &d->ray, d->window.x);
		d->window.x++;
	}
	return (SUCCESS);
}

/**
 * @brief render the frame with the texture pixels
 *
 * @param d data struct
 * @return int
 */
static int	render_frame(t_data *d)
{
	d->window.y = 0;
	while (d->window.y < HEIGHT)
	{
		d->window.x = 0;
		while (d->window.x < WIDTH)
		{
			if (d->texture_pix[d->window.y][d->window.x] > 0)
				d->window.color = d->texture_pix[d->window.y][d->window.x];
			else if (d->window.y < HEIGHT / 2)
				d->window.color = d->texture_det.hex_ceiling;
			else if (d->window.y < HEIGHT - 1)
				d->window.color = d->texture_det.hex_floor;
			set_image_pixel(&d->window.screen, d->window.x, \
			d->window.y, d->window.color);
			d->window.x++;
		}
		d->window.y++;
	}
	return (SUCCESS);
}

int	render_images(t_data *data)
{
	init_texture_pixels(data);
	calc_raycast(data);
	render_frame(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win, \
	data->window.screen.img, 0, 0);
	return (0);
}
