/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:17:34 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/12 19:04:36 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*buf;
	size_t	i;
	char	*s;

	if (!buf)
	{
		i = BUFFER_SIZE;
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		read(fd, buf, i);
	}
	s = get_line(&buf);
	return (s);
}

int	main()
{
	int	fd = open("test.txt", O_RDWR | O_CREAT, 0777);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}
