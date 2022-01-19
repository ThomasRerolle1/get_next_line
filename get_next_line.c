/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:17:34 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/19 14:31:38 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	int			rd_bytes;

	if (fd <= 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr((const char *)buffer, '\n') && 0 < rd_bytes)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (NULL);
		//printf("rd_bytes = %i\n", rd_bytes);
		buffer[rd_bytes] = '\0';
		//printf("buffer = %s\n", buffer);
		save = ft_strjoin(save, buffer);
	}
	return (save);
}

int	main()
{
	int	fd = open("test.txt", O_RDWR | O_CREAT, 0777);

	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(-1));
	printf("%s\n\n", get_next_line(0));
	printf("%s\n\n", get_next_line(4096));
	printf("%s\n\n", get_next_line(fd));
	close(fd);
	return (0);
}
