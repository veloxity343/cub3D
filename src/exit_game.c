/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:12:40 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/14 17:18:04 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    good_exit_game(t_data *data)
{
    ft_free_data(data);
    exit(0);
}

void    bad_exit_game(t_data *data)
{
    ft_free_data(data);
    exit(1);
}