/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:17:34 by trerolle          #+#    #+#             */
/*   Updated: 2022/03/24 15:56:53 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **save)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	

	if (*save == NULL)
		return (NULL);
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	line = ft_strndup(*save, 0, i);
	if (hasLine(*save) == 0)
		tmp = NULL;
	else
			tmp = ft_strndup(*save, i + 1, ft_strlen(*save));

	free(*save);
	*save = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			n;

	if (fd <= 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save && hasLine(save) == 1)
		return (get_line(&save));
	n = read(fd, buffer, BUFFER_SIZE);
	buffer[n] = 0;
	while (n > 0 && n <= BUFFER_SIZE)
	{
		save = (char *)ft_strjoin(save, buffer);
		if (hasLine(save) == 1)
			break;
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
	}
	//free(buffer);
	return (get_line(&save));
}
/*
int	main()
{
	
	int	fd = open("test3.txt", O_RDWR | O_CREAT, 0777);

	get_next_line(fd);
	close(fd);
	return (0);
	printf("%i\n", fd);
	printf("\n====================TEST_GET_NEXT_LINE=====================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("start%send", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));

	close(fd);

	fd = open("test.txt", O_RDWR | O_CREAT, 0777);
	//int	fd1 = open("test1.txt", O_RDWR | O_CREAT, 0777);
	char	*file = get_next_line(fd);

	
	printf("\n===========================TEST_GET_LINE==============================\n");
	char	*line = get_line(NULL);
	printf("%s", line);
	printf("\n=========================================================\n");
	char	*str1 = "Hollq \n\n\n\n\n get my line\0";
	char	*line1 = get_line(&str1);
	printf("%s", line1);
	printf("\n=========================================================\n");
	char	*line2 = get_line(&file);
	printf("%s", line2);
	printf("\n=========================================================\n");
	char	*str3 = "";
	char	*line3 = get_line(&str3);
	printf("%s\n\n", line3);
	
	
	close(fd);	
	
	
	

}*/
