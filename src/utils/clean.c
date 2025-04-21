/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:17:12 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/21 21:22:36 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_tex_info(t_tex *tex)
{
	free(tex->north);
	free(tex->south);
	free(tex->west);
	free(tex->east);
	free(tex->floor);
	free(tex->ceiling);
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
	free(*str);
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
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	free_game(t_game *game)
{
	free_tab((void **)game->cub_file);
	free_tab((void **)game->tex);
	free_tab((void **)game->tex_px);
	free_tex_info(&game->tex_info);
	free_map(game);
	return (FAILURE);
}
