#include "get_next_line.h"

int		IndexOf(char *s1, char c);
char	*ft_strndup(char *save, size_t start, size_t end);
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

void	uppdate_save(char **save)
{
	char	*new_save;

	if (!(*save))
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
	{
		i++;
	}
	if (s1[i] != c)
		return (-1);
	printf("%i\n", i);
	return (i);
}

int	main(void)
{
	char	*save = ft_strdup("bonjour \n\ncomo est");
	printf("get_line = %s", ft_strndup(save, 0, (size_t)ft_findIndexOf(save, '\n')));
	printf("save_line = %s", ft_strndup(save, (size_t)(ft_findIndexOf(save, '\n') + 1), ft_strlen(save)));
	printf("ge_line = %s", get_line(save));
	uppdate_save(&save);
	printf("update_save = %s\n", save);

	return (0);
}
	
