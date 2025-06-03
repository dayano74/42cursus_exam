#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);

int main(void)
{
	int fd;

	fd = open("doc", O_RDONLY);
	printf("fd = %d\n", fd);

	char *line;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}

	return(0);
}
