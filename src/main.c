/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:30:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/03 21:46:15 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Will return the error message based on the error code
 * @param error Error code
 * @return const char* Error message
 */
int	ft_error_msg(t_err error, int status_code)
{
	const char *msg = ft_get_err_msg(error);
	ft_putstr_fd("error: ", STDERR_FILENO);
	ft_putendl_fd((char *)msg, STDERR_FILENO);
	return (status_code);
}

/**
 * @brief Will validate the inputs of program.
 * Then, will populate structures by params / handler arguments
 * @param data Data structure
 * @param argv Argument vector
 * @return int value of validations
 */
static int	ft_args_handler(t_data *data, char **argv)
{
	if (ft_valid_cub_file(argv[1]) == false)
		return (ft_error_msg(ERR_CUB, 4));
	ft_init_map_handler(data, argv[1]);
	if (ft_file_to_variable(data) != 0)
		return (ft_free_data(data));
	if (ft_valid_map(data) != 0)
		return (ft_free_data(data));
	if (ft_valid_texture(&data->texture_det) != 0)
		return (ft_free_data(data));
	return (0);
}

/**
 * @brief Will initialize the mlx and window
 * structures and will call the setup_textures function
 * to load all textures.
 * @param data Data structure
 */
static void	ft_init_window(t_data *data)
{
	data->view.mlx = mlx_init();
	if (data->view.mlx == NULL)
	{
		ft_error_msg(ERR_MLX_INIT, 5);
		exit(EXIT_FAILURE);
	}
	ft_setup_textures(data);
	ft_set_player_direction(&data->player);
	data->view.win = mlx_new_window(data->view.mlx, WIDTH, HEIGHT, TITLE);
	if (data->view.win == NULL)
	{
		ft_error_msg(ERR_MLX_WIN, 5);
		exit(EXIT_FAILURE);
	}
	init_img(data, &data->window.screen, WIDTH, HEIGHT);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_error_msg(ERR_ARGS, 1));
	ft_bzero(&data, sizeof(t_data));
	if (ft_args_handler(&data, argv) != 0)
		return (EXIT_FAILURE);
	ft_starting_game(&data);
	mlx_loop(data.window.mlx);
	good_exit_game(&data);
	return (EXIT_SUCCESS);
}
