/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:13:16 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/12 19:10:18 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_line(char **buf)
{
	char	*s;
	int		c;

	c = ft_strlen(*buf);

	if (c == 0)
	{
		return ("NULL");
	}
	if (!(**buf))
	{
		free(*buf);
		printf("%s\n", *buf);
	}
	s = (char *)malloc((c + 1) * sizeof(char));
	c = 0;

	while (**buf != '\n' && **buf != '\0')
	{
		s[c++] = **buf;
		
		(*buf)++;
	}
	s[c] = '\0';
	(*buf)++;
	printf("%s\n", *buf);

	return (s);
}
