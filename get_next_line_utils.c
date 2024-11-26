/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:05:55 by mlaffita          #+#    #+#             */
/*   Updated: 2024/11/26 15:20:15 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*p_s;

	if (!s)
		return (0);
	p_s = s;
	while (*p_s)
		p_s++;
	return (p_s - s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	to_copy;
	size_t	i;

	len_src = ft_strlen(src);
	if (dstsize)
	{
		if (len_src >= dstsize)
			to_copy = dstsize - 1;
		else
			to_copy = len_src;
		i = 0;
		while (i < to_copy)
		{
			dst[i] = src[i];
			i++;
		}
		dst[to_copy] = '\0';
	}
	return (len_src);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;

	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(dup, s1, n + 1);
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(str, s1, len_s1 + 1);
		free(s1);
	}
	ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*p_s;

	p_s = s;
	while (*p_s)
	{
		if (*p_s == (char) c)
			return ((char *) p_s);
		p_s++;
	}
	if (*p_s == (char) c)
		return ((char *) p_s);
	return (NULL);
}
