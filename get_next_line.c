/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:17:34 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/19 18:22:30 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **save)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (*save == NULL)
		return (NULL);
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
	{
		i++;
	}
	//printf("%i\n", i);
	line = (char *)malloc((i + 1) * sizeof(char));
	j = 0;
	while (j < i)
	{
		//printf("j = %i\n", j);
		line[j] = (*save)[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
char	*update_save(char **save)
{
	char	*tmp_save;

	tmp_save = ft_strdup(ft_strchr(*save, '\n'));
	if (!tmp_save)
		tmp_save = ft_strdup(ft_strchr(*save, '\0'));

	printf("tmp_save = %s\n", tmp_save);
	free(*save);
	*save = tmp_save;
	free(tmp_save);
	return (*save);
}



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
	while (!ft_strchr(buffer, '\n') && 0 < rd_bytes)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (NULL);
		buffer[rd_bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	return (save);
}

int	main()
{
	/*
	int	fd = open("test.txt", O_RDWR | O_CREAT, 0777);

	
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
	printf("%s", get_next_line(fd));

	close(fd);
	*/
	
	printf("\n===========================TEST_GET_LINE==============================\n");
	char *str = NULL;
	char	*line = get_line(&str);
	printf("%s\n", line);
	printf("\n===========================TEST_UPDATE_SAVE==============================\n");
	char *s2 = "Hollaii";
	char	*save = update_save(&s2);
	printf("strchr = %s\n", ft_strchr(save, '\n'));
	printf("%s\n", save);

	return (0);
}
