/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:17:34 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/25 13:53:37 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *save)
{
	char	*line;

	if (save == NULL)
		return (NULL);
	if (IndexOf(save, '\n') < 0)
		return (save);
	line = ft_strndup(save, 0, (size_t)IndexOf(save, '\n')); 
	return (line);
}

void	update_save(char **save)
{
	char	*new_save;

	if (!(*save) || !save)
		return ;
	if (!(IndexOf(*save, '\n')))
	{
		free(*save);
		*save = NULL;
		return ;
	}
	new_save = ft_strndup(*save, (size_t)(IndexOf(*save, '\n') + 1), ft_strlen(*save));
	free(*save);
	*save = new_save;
}



char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	int			rd_bytes;
	char		*line;

	if (fd <= 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	//buffer[0] = '\0';
	rd_bytes = 1;
	while (!ft_strchr(buffer, '\n') && 0 < rd_bytes)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		printf("%s", buffer);
		if (rd_bytes -1)
			return (NULL);
		buffer[rd_bytes] = 0;
		save = ft_strjoin(save, buffer);
	}

	printf("%s", buffer);
	printf("%s", save);
	line = get_line(save);
	update_save(&save);
	return (line);
}

int	main()
{
	
	int	fd = open("test.txt", O_RDWR | O_CREAT, 0777);

	printf("\n====================TEST_GET_NEXT_LINE=====================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s", get_next_line(fd));
	printf("\n=========================================================\n");
	printf("%s\n\n", get_next_line(fd));

	close(fd);

	fd = open("test.txt", O_RDWR | O_CREAT, 0777);
	int	fd1 = open("test1.txt", O_RDWR | O_CREAT, 0777);
	char	*file = get_next_line(fd);
	char	*file1 = get_next_line(fd);

	
	printf("\n===========================TEST_GET_LINE==============================\n");
	char	*line = get_line(NULL);
	printf("%s", line);
	printf("\n=========================================================\n");
	char	*str1 = "Hollq \n\n\n\n\n get my line\0";
	char	*line1 = get_line(str1);
	printf("%s", line1);
	printf("\n=========================================================\n");
	char	*line2 = get_line(file);
	printf("%s", line2);
	printf("\n=========================================================\n");
	char	*str3 = "";
	char	*line3 = get_line(str3);
	printf("%s\n\n", line3);
	
	
	
	
	
	
	printf("\n===========================TEST_UPDATE_SAVE==============================\n");
	printf("%s\n", file1);
	update_save(&file1);
	printf("%s\n", file1);

	printf("\n=========================================================\n");

	close(fd);
	return (0);
}

