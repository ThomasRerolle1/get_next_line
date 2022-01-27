/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:13:16 by trerolle          #+#    #+#             */
/*   Updated: 2022/01/27 18:50:38 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (len);
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

	size_d = ft_strlen(s1) + ft_strlen(s2);
	d = malloc((size_d + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	if (s1)
		while (s1[i])
			d[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			d[i++] = s2[j++];
	d[i] = '\0';
	free(s1);
	return (d);
}

char	*ft_strchr(const char *s, int c)
{

	if (s)
		while ((char)*s != (char )c)
		{
			if ((char)*s == '\0')
				return (NULL);
			s++;
		}
	return ((char *)s);
}

char	*ft_strndup(char *save, size_t start, size_t end)
{
	char	*dst;
	int		i;

	i = 0;
	if (end < start || start < 0 || end > ft_strlen(save))
		return (NULL);
	dst = (char *)malloc((end - start + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	while (start <= end)
		dst[i++] = save[start++];
	dst[i] = '\0';	
	return (dst);
}

int	IndexOf(char *s1, char c)
{
	int	i;

	i = 0;
	if (!s1)
		return (-2);
	if (c == '\0')
		return ((int)ft_strlen(s1));
	while (s1[i] != c && s1[i] != '\0')
		i++;
	if (s1[i] != c)
		return (-1);
	return (i);
}
