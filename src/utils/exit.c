/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:51 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/14 16:33:54 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_exit_and_free(t_data *data, int s_code)
{
	if (!data)
		exit(s_code);
	if (data->window.win && data->window.mlx)
		mlx_destroy_window(data->window.mlx, data->window.win);
	if (data->window.mlx)
	{
		mlx_destroy_display(data->window.mlx);
		mlx_loop_end(data->window.mlx);
		free(data->window.mlx);
	}
	ft_free_data(data);
	exit(s_code);
}

void	ft_exit_cub(t_data *data, int exit_code)
{
	ft_free_data(data);
	exit(exit_code);
}
