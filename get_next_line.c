/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:17:34 by trerolle          #+#    #+#             */
/*   Updated: 2022/03/28 13:35:03 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **save)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	if (save == NULL || *(save) == NULL)
		return (NULL);
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	line = ft_strndup(*save, 0, i);
	if (hasLine(*save) == 0)
	{
		tmp = NULL;
	}
	else
		tmp = ft_strndup(*save, i + 1, ft_strlen(*save));

	free(*save);
	*save = tmp;

	//printf("line=%s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			n;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save && hasLine(save) == 1)
		return (get_line(&save));
	n = read(fd, buffer, BUFFER_SIZE);
	if (n < 0)
	{
		free(save);
		return (NULL);
	}
	buffer[n] = '\0';
	while (n > 0)
	{
		save = ft_strjoin(save, buffer);
		if (hasLine(save) == 1)
			break;
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
//		printf("save='%s'\n", save);
	}
	//free(buffer);i
	return (get_line(&save));
}
/*
int	main()
{
	int	fd = open("test3.txt", O_RDWR | O_CREAT, 0777);
	
	char	*line;
	while ((line = get_next_line(fd)))
		printf("line = '%s'\n", line);
	printf("line = '%s'\n", line);
}*/
