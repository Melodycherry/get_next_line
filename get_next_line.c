/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:49:22 by mlaffita          #+#    #+#             */
/*   Updated: 2024/11/25 13:36:28 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	int			rd;
	static char	buffer[BUFFER_SIZE + 1];
	char		*d_buff;
	char		*n_buff;
	char		*line;

	rd = 1;
	line = NULL;
	d_buff = buffer;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd != 0)
			buffer[rd] = '\0';
		n_buff = ft_strchr(buffer, '\n');
		if (n_buff)
		{
			line = ft_strndup(buffer, (n_buff - d_buff) + 1);
			ft_strlcpy(buffer, n_buff + 1, BUFFER_SIZE - (n_buff - d_buff));
			return (line);
		}
		else
			line = ft_strjoin(line, buffer);
			buffer[0] = '\0';
			if (rd == 0)
			{
				if (line && *line != '\0')
					return (line);
				free(line);
				return (NULL);
			}
	}
}

/*
#include <stdio.h>
#include <fcntl.h>
int	main (int ac, char **av)
{
	int 	fd;
	char	*line;

	fd = open(*(av + 1), O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free (line);
	}
}
*/