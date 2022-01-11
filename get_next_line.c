#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	static int	x = 0;
	static char	buf[9];
	if (buf == '\n' && read(fd, buf, 1) == '\n')
		ft_putstr_fd("NULL", 1);
	while (buf != '\n')
	{
		read(fd, buf, 1);
		ft_putchar_fd(1, buf, 1);
	}	
	return (buf);
}

int	main()
{
	int	fd = open("test.txt", O_RDWR | O_CREAT, 0777);
	printf("%s, %i", get_next_line(fd), fd);
	return (0);
}
