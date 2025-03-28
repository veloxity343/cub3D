/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:12:40 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/28 19:15:11 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief use exit(0) Exit program 
 * Will free all data before exit
 * @param data Main data structure
 */
void    good_exit_game(t_data *data)
{
    ft_free_data(data);
    exit(0);
}

/**
 * @brief use exit(1) Exit program
 * Will free all data before exit
 * @param data Main data structure
 */
void    bad_exit_game(t_data *data)
{
    ft_free_data(data);
    exit(1);
}
