/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:13:16 by trerolle          #+#    #+#             */
/*   Updated: 2022/03/28 13:32:54 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s)
		while (s[len] != '\0')
			len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	
	char	*d;
	int		size_d;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size_d = ft_strlen(s1) + ft_strlen(s2);
//	printf("size_d=%d\n", size_d);
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

int	hasLine(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
	}

	return (0);
}

char	*ft_strndup(char *save, int start, int end)
{
	char	*dst;
	int		i;

	i = 0;
	if (end < start || start < 0 || ft_strlen(save) <= start)
		return (NULL);
	if (end > ft_strlen(save))
		end = ft_strlen(save) - 1;
	dst = (char *)malloc((end - start + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	while (start <= end)
		dst[i++] = save[start++];
	dst[i] = '\0';	
	return (dst);
}

