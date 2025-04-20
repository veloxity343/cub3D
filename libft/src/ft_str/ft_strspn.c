/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:55:23 by rcheong           #+#    #+#             */
/*   Updated: 2025/04/20 17:55:23 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    int j, found;

    while (s[i] != '\0')
    {
        found = 0;
        j = 0;
        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
            {
                found = 1;
                break;
            }
            j++;
        }
        if (!found)
            break;
        i++;
    }
    return i;
}
