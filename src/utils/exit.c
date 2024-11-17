/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:34:51 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/15 14:35:07 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_and_free(t_data *data, int s_code)
{
	if (!data)
		exit(s_code);
	if (data->view.win && data->view.mlx)
		mlx_destroy_window(data->view.mlx, data->view.win);
	if (data->view.mlx)
	{
		mlx_destroy_display(data->view.mlx);
		mlx_loop_end(data->view.mlx);
		free(data->view.mlx);
	}
	ft_free_data(data);
	exit(s_code);
}

void	ft_exit_cube(t_data *data, int exit_code)
{
	ft_free_data(data);
	exit(exit_code);
}
