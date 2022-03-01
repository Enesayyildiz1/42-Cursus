#include<unistd.h>
#include<stdio.h>

static int check_doubles(char *str, char c, int pos)
{	
	int i;
	i = 0;
	
	while (i < pos)
	{
		if(str[i] == c)
			return (0);
		i++;
	}
	return (1);

}

int main(int argc, char **argv)
{
	char *str;
	char *set;
	int i;
	int j;
	if(argc == 3)
	{

		str = argv[1];
		set = argv[2];
		
		i=0;
		while (str[i]!='\0')
		{
			j=0;
			while(set[j]!='\0')
			{
				if(str[i]==set[j])
				{
					if(check_doubles(str,str[i],i)==1)
					{
						write(1, &str[i], 1);
						break;
					}
				}
				j++;
			}
			i++;
		}

		write(1,"\n",1);
	}
	else
	{
		write(1,"\n",1);
	}
}
