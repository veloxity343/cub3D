/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:30:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/03/16 11:30:29 by rcheong          ###   ########.fr       */
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
static int	ft_args_handler(t_data *data, char *argv)
{
	if (ft_valid_cub_file(argv) == false)
		return (ft_error_msg(ERR_CUB, 4));
	if (valid_data(data, argv))
		return (1);
	if (!data->cub_file[6])
		return (ft_error_msg(ERR_MAP, 1));
	else
		get_map_details(data, data->cub_file + 6);
	if (valid_map(data, data->map))
		return (1);
	return (0);
}

/**
 * @brief Will initialize the mlx and window
 * structures and will call function
 * to load all textures.
 * @param data Data structure
 */
static int	ft_init_window(t_data *data, char *argv)
{
	data->window.mlx = mlx_init();
	if (data->window.mlx == NULL)
	{
		ft_error_msg(ERR_MLX_INIT, 5);
		exit(EXIT_FAILURE);
	}
	if (ft_args_handler(data, argv))
		bad_exit_game(data);
	ft_set_player_direction(&data->player);
	data->window.win = mlx_new_window(data->window.mlx, WIDTH, HEIGHT, TITLE);
	if (data->window.win == NULL)
	{
		ft_error_msg(ERR_MLX_WIN, 5);
		bad_exit_game(data);
	}
	// init function to set pixels after creation of mlx window (mlx_new_img)
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_error_msg(ERR_ARGS, 1));
	ft_bzero(&data, sizeof(t_data));
	if (ft_init_window(&data, argv[1]))
		return (EXIT_FAILURE);
	// ft_start_game(&data);
	mlx_loop(data.window.mlx);
	good_exit_game(&data);
	return (EXIT_SUCCESS);
}
