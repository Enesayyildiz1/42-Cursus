#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>

int ft_putstr(char *str)
{
	int len=0;
	while(*str != '\0')
		len += write(1, str++, 1);
	return (len);
}
int ft_putchar(char c)
{
	int sayi=0;
	sayi+=write(1, &c, 1);
	return sayi;
}
int ft_putnbr(int num, char *base, int baseset)
{
	int len;

	len=0;
	if(num==-2147483648)
		len += ft_putstr("-2147483648");
	if(num<0)
	{
		num = num * -1;
		ft_putchar('-');
		len++;
	}
	if(num>baseset-1)
		len += ft_putnbr(num/baseset, base, baseset);
	len+=ft_putchar(base[num%baseset]);
	return len;
}
int arg_printer(va_list macro, char c)
{
	if(c == 's')
		return (ft_putstr(va_arg(macro, char *)));
	if(c == 'd')
		return (ft_putnbr(va_arg(macro, int), "0123456789",10));
	if(c == 'x')
		return (ft_putnbr(va_arg(macro, unsigned int),"0123456789abcdef",16));
	return (0);
}

int ft_printf(const char *str, ...)
{
	int len=0;
	int i=0;
	va_list macro;

	va_start(macro,str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			len += arg_printer(macro, str[i+1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(macro);
	return len;
}
int main()
{
	char *name="Enes";
	int a=ft_putstr(name);
	ft_printf("%s",name);
	ft_printf("%d", 42);
	ft_printf("%x", 42);
}

