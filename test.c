/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:00 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/04/25 15:25:29 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)s + strlen(s));
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

//s2 have no data return s1 poiner position
//found s2 return s1 position
//have not find s2 return NULL
char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	str2;
	size_t	j;

	i = 0;
	str2 = strlen(s2);
	if (!s1 && len == 0)
		return (NULL);
	if (str2 == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j < len))
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}

int main()
{
    char s1[] = "Hello, world! aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\naaa\n";
    char s2[] = "world";
    size_t n = 13;

    char *result = ft_strnstr(s1, s2, n);
    if (result)
    {
        printf("Found: %s\n", result);
        char *chr = ft_strchr(result, '\n');
        printf("Found: %s\n", chr);
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}
