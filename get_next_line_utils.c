/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:13:16 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/19 14:33:33 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	//if (s[0] == '\0' )
	//	return (len);
	while (s[len])
	{
		len++;
	}
	//printf("len = %zu\n", len);
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	
	char			*d;
	unsigned int	size_d;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1 = "\0";
	}
	
	size_d = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	//printf("size_d = %i\n", size_d);
	d = malloc((size_d + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (s1[i])
		d[i++] = s1[j++];
	j = 0;
	while (s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	while (*s1 != (char )c)
	{
		if (*s1 == '\0')
			return ((char *) NULL);
		s1++;
	}
	return (s1);
}
