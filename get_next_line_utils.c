/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:13:16 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/20 11:25:05 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
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
	
	size_d = ft_strlen(s1) + ft_strlen(s2);
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

char	*ft_strchr(char *s, int c)
{
	while (*s != (char )c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

char	*ft_strdup(char *s1)
{
	int		count;
	int		i;
	char	*ptr;

	i = 0;
	count = ft_strlen(s1);
	ptr = malloc((count + 1) * sizeof(*s1));
	if (ptr == NULL)
		return (ptr);
	while (i < count)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
