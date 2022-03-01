#include<unistd.h>
#include<stdio.h>

int ft_strlen(char *x)
{
	int i=0;
	while(x[i]!='\0')
		i++;
	return i;
}
int check_doubles(char *str, char c, int pos)
{
	int i;

	i = 0;
	while(i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i=0;
	int j=0;
	int z=0;
	char used[128];

	while(j<128)
		used[j++]='\0';
	if(argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			if(check_doubles(argv[1],argv[1][i], i)==1)
			{
				write(1,&argv[1][i],1);
			}
			i++;
		}
		i=0;

		while(argv[2][i])
		{
			if((check_doubles(argv[1],argv[2][i], ft_strlen(argv[1]))==1))
			{
				if(check_doubles(argv[2], argv[2][i],i)==1)
					write(1,&argv[2][i],1);
			}		
			i++;
		}
		write(1,"\n",1);	
	}

}
