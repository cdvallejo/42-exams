#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	int i;

	i = 0;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_count(int n)
{
	int count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putdigit(long n)
{
	int count;

	count = ft_count(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putdigit(n / 10);
		ft_putdigit(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (count);
}

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printhex(unsigned int hex)
{
	static int count;
	
	count = 0;
	if (hex >= 16)
		ft_printhex(hex / 16);
	count+=	write(1, &"0123456789abcdef"[hex % 16], 1);
	return (count);
}

int ft_printf(const char *format, ... )
{
	va_list	things;
	va_start(things, format);
	int i;
	int total;

	i = 0;
	total = 0;
	while (format[i])
	{
		if ((format[i] == '%') && (format[i + 1]  == 's' || format[i + 1] == 'd' || format[i + 1] == 'x'))
		{
			format++;
			if (format[i] == 's')
				total += ft_putstr(va_arg(things, char *));
			if (format[i] == 'd')
				total += ft_putdigit(va_arg(things, int));
			if (format[i] == 'x')
				total += ft_printhex(va_arg(things, unsigned int));
		}
		else
			total += ft_putchar(format[i]);
		i++;
	}
	va_end(things);
	//printf("\nCaracteres: %d", total);
	return (total);
}
/*
int main()
{
	unsigned int n;
	n = 42;
	ft_printf("%x", n);
	//printf("%d", n);
}*/