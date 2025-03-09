/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:51:56 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/09 15:31:20 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    print_arr(char **arr)
{
    int i = -1;
    
    ft_putendl_fd("debug: ", 2);
    while (arr[++i])
        ft_putendl_fd(arr[i], 2);
}

void    debug(int n)
{
    ft_putstr_fd("debug", 2);
    ft_putnbr_fd(n, 2);
    ft_putendl_fd(" ", 2);
}

// void    err(char *message, int q)
// {
//     ft_putendl_fd(message, 2);
//     if (q)
//         exit(1);
// }

void    free_arr(char **arr)
{
    int i;

    i = -1;
    if (!arr || !arr[0])
        return ;
    while (arr[++i])
        free(arr[i]);
    if (arr)
        free(arr);
}

int ft_arrlen(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

char    **ft_arrdup_n(char **arr, int n)
{
    int i;
    char    **new;

    i = 0;
    if (!arr || !arr[0])
        return (NULL);
    new = malloc((n + 1) * sizeof(char *));
    if (!new)
        return (NULL);
    while (arr[i] && i < n)
    {
        new[i] = ft_strdup(arr[i]);
        if (!new[i])
        {
            free_arr(new);
            return (NULL);
        }
        i++;
    }
    new[i] = NULL;
    return (new);
}

char    **ft_arrdup(char **arr)
{
    int i;
    char    **new;

    i = -1;
    if (!arr || !arr[0])
        return (NULL);
    new = malloc(ft_arrlen(arr) * sizeof(char *));
    if (!new)
        return (NULL);
    while (arr[++i])
    {
        new[i] = ft_strdup(arr[i]);
        if (!new[i])
        {
            free_arr(new);
            return (NULL);
        }
    }
    new[i] = NULL;
    return (new);
}

char    *ft_strjoin_free(char *s1, char *s2)
{
    char *new;

    if (!s2)
        return (NULL);
    if (!s1)
        s1 = ft_calloc(1, 1);
    new = ft_strjoin(s1, s2);
    if (s1)
        free(s1);
    return (new);
}