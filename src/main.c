#include "cub3d.h"

/**
 * @brief Will return the error message based on the error code
 * @param error Error code
 * @return const char* Error message
 */
int	ft_error_msg(t_err error, int status_code)
{
	const char *msg = ft_get_err_msg(error);
	ft_putstr_fd("error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
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
	// file parser (color, textures, white space, etc.) -> then return to free data if invalid (??)
	if (ft_valid_map(data) != 0)
		return (ft_free_data(data));
	if (ft_valid_texture(&data->texture_det) != 0)
		return (ft_free_data(data));
	return (0);
}

/**
 * @brief Will initialize the mlx and window
 * structures and will call function
 * to load all textures.
 * @param data Data structure
 */
static void	ft_init_window(t_data *data)
{
	data->window.mlx = mlx_init();
	if (data->window.mlx == NULL)
	{
		ft_error_msg(ERR_MLX_INIT, 5);
		exit(EXIT_FAILURE);
	}
	// parser for textures
	ft_set_player_dir(&data->player);
	data->window.win = mlx_new_window(data->window.mlx, WIDTH, HEIGHT, TITLE);
	if (data->window.win == NULL)
	{
		ft_error_msg(ERR_MLX_WIN, 5);
		exit(EXIT_FAILURE);
	}
	// init function to set pixels after creation of mlx window (mlx_new_img)
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_error_msg(ERR_ARGS, 1));
	ft_bzero(&data, sizeof(t_data));
	if (ft_args_handler(&data, argv) != 0)
		return (EXIT_FAILURE);
	ft_init_window(&data);
	ft_start_game(&data);
	mlx_loop(data.window.mlx);
	return (EXIT_SUCCESS);
}
