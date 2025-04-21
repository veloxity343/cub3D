/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:51:56 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/21 18:16:52 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char    **read_file(char *path)
{
    int fd;
    char    *temp;
    char    *readd;
    char    **cub_file;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (NULL);
    temp = get_next_line(fd);
    readd = ft_calloc(1, 1);
    while (temp)
    {
        readd = ft_strjoin_free(readd, temp);
        ft_free1(temp);
        temp = get_next_line(fd);
    }
    cub_file = ft_split(readd, '\n');
    if (!cub_file)
        return (NULL);
    ft_free1(readd);
    return (cub_file);
}

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

char    **ft_arrdup(char **arr)
{
    int i;
    char    **new;

    i = -1;
    if (!arr || !arr[0])
        return (NULL);
    new = malloc((ft_arrlen(arr) + 1) * sizeof(char *));
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
