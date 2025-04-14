/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:26:03 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/14 18:50:36 by yyan-bin         ###   ########.fr       */
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
	d->view.x = 0;
	while (d->view.x < WIDTH)
	{
		ft_setup_raycast_info(d->view.x, &d->ray, &d->player);
		ft_calc_dda(&d->ray, &d->player);
		ft_perform_dda(d, &d->ray);
		ft_calc_line_height(&d->ray, &d->player);
		d->view.x++;
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
	// int pixel;
	int *pixels = (int *)d->view.screen.addr;
	
	d->view.y = 0;
	while (d->view.y < HEIGHT)
	{
		d->view.x = 0;
		while (d->view.x < WIDTH)
		{
			update_text_pixels(d, &d->texture_det, &d->ray, d->view.x);
			if (d->texture_pixels[d->view.y][d->view.x] > 0)
				d->view.color = d->texture_pixels[d->view.y][d->view.x];
			else if (d->view.y < HEIGHT / 2)
				d->view.color = d->texture_det.hex_ceiling;
			else if (d->view.y < HEIGHT - 1)
				d->view.color = d->texture_det.hex_floor;
			pixels[d->view.y * (d->view.screen.size_line/4) + d->view.x] = d->view.color;
			// printf("screen: %c\n", d->view.screen.addr[d->view.x]);
			// if (d->view.x % 4 == 0)
			// pixel = d->view.y * (d->view.screen.size_line / 4) + d->view.x;
			// d->view.screen.addr[pixel] = d->view.color;
			d->view.x++;
		}
		// debug(d->view.y);
		d->view.y++;
	}
	return (SUCCESS);
}

// static int ft_render_frame(t_data *d) {
// 	int *pixels = (int *)d->view.screen.addr;
    
// 	d->view.y = 0;
// 	while (d->view.y < HEIGHT)
// 	{
// 		d->view.x = 0;
// 		while (d->view.x < WIDTH)
// 		{
// 			update_text_pixels(d, &d->texture_det, &d->ray, d->view.x);
// 			if (d->texture_pixels[d->view.y][d->view.x] > 0) {
// 				// debug(0);
//                 d->view.color = d->texture_pixels[d->view.y][d->view.x];
//             } else if (d->view.y < HEIGHT / 2) {
// 				// debug(1);
//                 d->view.color = d->texture_det.hex_ceiling;
//             } else {
// 				// debug(2);
//                 d->view.color = d->texture_det.hex_floor;
//             }
//             pixels[d->view.y * (d->view.screen.size_line / 4) + d->view.x] = d->view.color;
// 			d->view.x++;
//         }
// 		d->view.y++;
//     }
//     return SUCCESS;
// }

int	ft_render_images(t_data *data)
{
	if (data->texture_det.index == NORTH)
		printf("north\n");
	else if (data->texture_det.index == EAST)
		printf("east\n");
	else if (data->texture_det.index == WEST)
		printf("west\n");
	else if (data->texture_det.index == SOUTH)
		printf("south\n");
	init_texture_pix(data);
	ft_calc_raycast(data);
	ft_render_frame(data);
	mlx_put_image_to_window(data->view.mlx, data->view.win, \
	data->view.screen.img, 0, 0);
	return (0);
}
