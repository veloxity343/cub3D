/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:30:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/26 13:39:00 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_data(t_game *data, char *path)
{
	char	*file;
	int		flag;

	flag = 0;
	file = read_file(path);
	if (!file)
		return (error_msg(0, FILE_INVALID, 1, 0));
	data->cub_file = ft_split(file, '\n');
	if (!data->cub_file || valid_image(data, data->cub_file)
		|| valid_rgb(data, data->cub_file + 4))
		flag = 1;
	if (flag != 1 && !data->cub_file[6])
		error_msg(NULL, MAP_MISSING, 1, flag++);
	if (flag != 1 && check_map_double_newline(file))
		error_msg(NULL, MAP_NO_WALLS, 1, flag++);
	ft_free1(file);
	return (flag);
}

static int	parse_args(t_game *game, char **argv)
{
	if (validate_file(argv[1], 1) == FAILURE)
		return (1);
	if (valid_data(game, argv[1]))
		return (1);
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
	render_raycast(&game);
	get_input(&game);
	mlx_loop_hook(game.mlx, render_img, &game);
	mlx_loop(game.mlx);
	return (0);
}
