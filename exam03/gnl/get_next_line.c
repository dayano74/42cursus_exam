#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

static int get_char(int fd)
{
	static char buf[BUFFER_SIZE];
	static int bytes_in_buf = 0;
	static int pos = 0;
	int ret;

	if (pos >= bytes_in_buf)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			return (-1);
		bytes_in_buf = ret;
		pos = 0;
	}
	return ((unsigned char)buf[pos++]);
}

char *get_next_line(int fd)
{
	char line[BUFFER_SIZE * 64];
	int i;
	int c;
	char *ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		c = get_char(fd);
		if (c == -1)
			break;
		line[i++] = (char)c;
		if (c == '\n')
			break;
		if (i >= (int)sizeof(line) - 1)
			break;
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	ret = (char *)malloc(i + 1);
	if (!ret)
		return (NULL);
	int j = 0;
	while(j <= i)
	{
		ret[j] = line[j];
		j++;
	}
	return (ret);
}
