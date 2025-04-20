/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:30:28 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 17:34:52 by rcheong          ###   ########.fr       */
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

static int	parse_args(t_game *game, char **av)
{
	if (validate_file(av[1], 1) == FAILURE)
		clean(game, FAILURE);
	parse_game(av[1], game);
	if (parse_file(game, game->map_info.file) == FAILURE)
		return (free_game(game));
	if (validate_map(game, game->map) == FAILURE)
		return (free_game(game));
	if (validate_tex(&game->tex_info, game) == FAILURE)
		return (free_game(game));
	init_player_dir(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (error_msg("Usage", USAGE, 1, 0));
	init_game(&game);
	if (parse_args(&game, av) != 0)
		return (1);
	init_mlx(&game);
	init_pattern(&game);
	print_controls();
	render_raycast(&game);
	get_input(&game);
	mlx_loop_hook(game.mlx, render_img, &game);
	mlx_loop(game.mlx);
	return (0);
}
