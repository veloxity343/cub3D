/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:26:03 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/26 17:07:47 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief calculate the raycast for each pixel
 *
 * @param d data struct
 * @return int
 */
static int	ft_calc_raycast(t_data *d)
{
	d->window.x = 0;
	while (d->window.x < WIDTH)
	{
		ft_setup_raycast_info(d->window.x, &d->ray, &d->player);
		ft_calc_dda(&d->ray, &d->player);
		ft_perform_dda(d, &d->ray);
		ft_calc_line_height(&d->ray, &d->player);
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
static int	ft_render_frame(t_data *d)
{
	int pixel;
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
			pixel = d->window.y * (d->window.screen.size_line / 4) + d->window.x;
			d->window.screen.addr[pixel] = d->window.color;
			d->window.x++;
		}
		d->window.y++;
	}
	return (SUCCESS);
}

int	ft_render_images(t_data *data)
{
	// need function to convert xpm to image. parse loop to render per frame
	ft_calc_raycast(data);
	ft_render_frame(data);
	mlx_put_image_to_window(data->window.mlx, data->window.win, \
	data->window.screen.img, 0, 0);
	return (0);
}
