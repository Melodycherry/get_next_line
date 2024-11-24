/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:49:44 by mlaffita          #+#    #+#             */
/*   Updated: 2024/11/24 17:57:29 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	s;
	unsigned int	i;

	s = 0;
	i = 0;
	while (src && src[s] != '\0')
		s++;
	if (size == 0)
		return (s);
	while (src && src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (s);
}

char	*ft_strndup(const char *src, unsigned int n)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, src, (n + 1));
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	if (s1)
		free(s1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == d)
			return ((char *) s);
		s++;
	}
	if (d == '\0')
		return ((char *) s);
	return (NULL);
}