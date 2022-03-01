#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

char *get_next_line(int fd)
{
	char *buff;
	char *dest;

	buff=malloc(1);
	dest=malloc(999);

	int i;
	int j;
	j=0;
	i=read(fd,buff,1);
	while (i > 0)
	{
		dest[j]=buff[0];
		if(buff[0]=='\n')
			break;
	
		i = read(fd, buff, 1);
		j++;
	}
	free(buff);
	return dest;
}

int main()
{
	int fd;
	fd=open("get_next_line.c", O_RDONLY);

	printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
	
	printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
}
