/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_magic_boxe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:46:37 by ascordil          #+#    #+#             */
/*   Updated: 2024/11/29 11:45:29 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_buffer(int fd, char **buffer, char **magic_boxe)
{
	char	*temp;
	ssize_t	readletter;

	readletter = 1 ;
	while (readletter > 0)
	{
		readletter = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[readletter] = '\0';
		if (readletter <= 0)
			break ;
		temp = ft_strjoin(*magic_boxe, *buffer);
		free(*magic_boxe);
		*magic_boxe = NULL;
		if (!temp)
			break ;
		*magic_boxe = temp;
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
}

static char	*return_next_ligne(char **magic_boxe)
{
	size_t	i;
	char	*to_return;
	char	*temp;

	i = 0;
	while (((*magic_boxe)[i] != '\n') && ((*magic_boxe)[i] != '\0'))
		i++;
	to_return = ft_substr(*magic_boxe, 0, i + ((*magic_boxe)[i] == '\n'));
	if (!to_return)
		return (free(*magic_boxe), *magic_boxe = NULL, NULL);
	if (((*magic_boxe)[i] == '\n') && ((*magic_boxe)[i + 1] != '\0'))
	{
		temp = ft_substr(*magic_boxe, i + 1, ft_strlen(*magic_boxe) - i);
		if (!temp)
			return (free(*magic_boxe), *magic_boxe = NULL
				, free(to_return), to_return = NULL, NULL);
		return (free(*magic_boxe), *magic_boxe = temp, to_return);
	}
	else
		return (free(*magic_boxe),*magic_boxe = NULL, to_return);
}

char	*get_next_line(int fd)
{
	static char		*magic_boxe;
	char			*buffer;
	char			*line;

	line = NULL;
	if (!magic_boxe)
		magic_boxe = ft_strdup("");
	if (!magic_boxe)
		return (free(magic_boxe), magic_boxe = NULL, NULL);
	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(magic_boxe), magic_boxe = NULL, NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(magic_boxe), magic_boxe = NULL, NULL);
	get_buffer(fd, &buffer, &magic_boxe);
	if (!magic_boxe || !*magic_boxe)
		return (free(buffer), buffer = NULL
			, free(magic_boxe), magic_boxe = NULL, NULL);
	line = return_next_ligne(&magic_boxe);
	return (free(buffer), buffer = NULL, line);
}
/*
int	main(void)
{
	int	fd;
	int	i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (i < 50)
	{
		printf("resultat%d:%s\n", i, get_next_line(fd));
		i++;
	}
	close(fd);
}
*/
