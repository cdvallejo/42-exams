#include <stdio.h>
#include <stdlib.h>

int ft_len(long num)
{
	int i;

	i = 1;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while(num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long num;
	char *str;
	int i;

	num = nbr;
	i = ft_len(num);
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	i--;
	if (num == 0)
		str[i] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[i] = 48 + (num % 10);
		num /= 10;
		i--;
	}
	return (str);
}

