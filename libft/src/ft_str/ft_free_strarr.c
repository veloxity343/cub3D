/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:10:30 by rcheong           #+#    #+#             */
/*   Updated: 2025/02/02 22:10:31 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strarr(char **arr_str)
{
	int	i;

	i = 0;
	if (arr_str)
	{
		while (arr_str[i])
		{
			if (arr_str[i])
			{
				free_ptr(arr_str[i]);
				arr_str[i] = NULL;
			}
			i++;
		}
		free(arr_str);
		arr_str = NULL;
	}
}
