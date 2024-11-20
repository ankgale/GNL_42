/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gale <gale@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:28:38 by gankaoua          #+#    #+#             */
/*   Updated: 2024/11/14 23:21:57 by gale             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc((len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (++i < ft_strlen(s1))
		join[i] = s1[i];
	i = -1;
	while (++i < ft_strlen(s2))
		join[i + ft_strlen(s1)] = s2[i];
	join[i + ft_strlen(s1)] = '\0';
	free((char *)s1);
	return (join);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ch;

	ch = (unsigned char *)s;
	while (n > 0)
	{
		*ch = 0;
		n--;
		ch++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb * size == 0)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
