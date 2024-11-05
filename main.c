#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("\n%s\n",line);
	free (line);
}
