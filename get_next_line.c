/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:49:22 by mlaffita          #+#    #+#             */
/*   Updated: 2024/11/24 20:58:06 by mlaffita         ###   ########.fr       */
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
				return (line);
			}
			
	}
}
/*
char *get_next_line(int fd)
{
    int         rd;
    static char buffer[BUFFER_SIZE + 1];
    char        *n_buff;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    while (1)
    {
        if (buffer[0] == '\0') // Si le buffer est vide, lire depuis le fichier
        {
            rd = read(fd, buffer, BUFFER_SIZE);
            if (rd == -1) // Erreur de lecture
                return (NULL);
            if (rd == 0) // Fin de fichier
                return (line); // Retourne la ligne accumulée ou NULL si vide
            buffer[rd] = '\0'; // Terminer le buffer lu
        }
        n_buff = ft_strchr(buffer, '\n'); // Cherche un '\n' dans le buffer
        if (n_buff) // '\n' trouvé
        {
            line = ft_strjoin(line, ft_strndup(buffer, n_buff - buffer + 1));
            ft_strlcpy(buffer, n_buff + 1, BUFFER_SIZE - (n_buff - buffer));
            return (line);
        }
        else // Pas de '\n', ajouter tout le buffer à la ligne
        {
            line = ft_strjoin(line, buffer);
            buffer[0] = '\0'; // Vider le buffer
        }
    }
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main (int ac, char **av)
// {
// 	int 	fd;
// 	char	*line;

// 	fd = open(*(av + 1), O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free (line);
// 	}
// }