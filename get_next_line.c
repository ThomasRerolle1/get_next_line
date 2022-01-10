#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	static int	x = 0;
	static char	buf[50];

	read(fd, buf, sizeof(buf));
	return (buf);
}

int	main()
{
	int	fd = open("test.txt", O_RDWR | O_CREAT, 0777);
	printf("%s, %i", get_next_line(fd), fd);
	write(2, "A", 1);
	return (0);
}
