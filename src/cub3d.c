/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:30:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/22 23:14:47 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_controls(void)
{
	ft_putendl_fd("\n\e[35mGAME CONTROLS:\e[0m", 1);
	ft_putendl_fd("\t\e[35mW:\e[0m Move forward", 1);
	ft_putendl_fd("\t\e[35mA:\e[0m Move left", 1);
	ft_putendl_fd("\t\e[35mS:\e[0m Move backward", 1);
	ft_putendl_fd("\t\e[35mD:\e[0m Move right", 1);
	ft_putendl_fd("\t\e[35m←:\e[0m Rotate left", 1);
	ft_putendl_fd("\t\e[35m→:\e[0m Rotate right", 1);
}

int	valid_data(t_game *data, char *path)
{
	data->cub_file = read_file(path);
	if (!data->cub_file)
		return (error_msg(0, FILE_INVALID, 1, 0));
	if (valid_image(data, data->cub_file))
		return (1);
	if (valid_rgb(data, data->cub_file + 4))
		return (1);
	return (0);
}

static int	parse_args(t_game *game, char **argv)
{
	if (validate_file(argv[1], 1) == FAILURE)
		return (1);
	if (valid_data(game, argv[1]))
		return (1);
	if (!game->cub_file[6])
		return (error_msg(NULL, MAP_MISSING, 1, 0));
	else
		get_map_details(game, game->cub_file + 6);
	if (valid_map(game, game->map))
		return (1);
	init_player_dir(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg(NULL, USAGE, 1, 0));
	init_game(&game);
	if (parse_args(&game, argv) != 0)
		clean(&game, FAILURE);
	init_mlx(&game);
	init_pattern(&game);
	print_controls();
	render_raycast(&game);
	get_input(&game);
	mlx_loop_hook(game.mlx, render_img, &game);
	mlx_loop(game.mlx);
	return (0);
}
