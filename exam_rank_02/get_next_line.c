#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
char *get_next_line(int fd)
{
	char *dst;
	char *buff;

	int j;
	int i;

	dst = malloc(999);
	buff = malloc(1);

	j= 0;
	i = read(fd, buff, 1);
	while(i > 0)
	{
		dst[j++] = buff[0];
		if (buff[0] == '\n')
			break;
		i = read(fd, buff, 1);
	}
	free(buff);
	return(dst);
}

int main()
{
	int fd;
	fd = open("get_next_line.c", O_RDONLY);

	printf("%s",get_next_line(fd));
}
