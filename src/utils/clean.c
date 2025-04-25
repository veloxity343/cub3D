/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:12 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/25 21:04:52 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_tex_info(t_tex *tex)
{
	ft_free1(tex->north);
	ft_free1(tex->south);
	ft_free1(tex->west);
	ft_free1(tex->east);
	ft_free1(tex->floor);
	ft_free1(tex->ceiling);
}

static void	free_map(t_game *game)
{
	if (game->map_info.fd > 0)
		close(game->map_info.fd);
	free_tab((void **)game->map_info.file);
	free_tab((void **)game->map);
}

char	*ft_free(char **str)
{
	ft_free1(*str);
	*str = NULL;
	return (NULL);
}

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_free1(tab[i]);
		i++;
	}
	ft_free1(tab);
}

/**
 * @brief Frees the game resources and exits the program.
 * @param game The game structure to clean up.
 * @return FAILURE if an error occurs, SUCCESS otherwise.
 * @details This function frees the game resources such as textures,
 * map, and other dynamically allocated memory. It also closes the
 * file descriptor if it is open.
 */
int	free_game(t_game *game)
{
	free_tab((void **)game->cub_file);
	free_tab((void **)game->tex);
	free_tab((void **)game->tex_px);
	free_tex_info(&game->tex_info);
	free_map(game);
	return (FAILURE);
}
