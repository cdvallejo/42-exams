#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int len;
	int *n;
	int i;
	len = (start - end) + 1;
	if (len < 0)
		len *= -1;
	n = (int *)malloc(sizeof(int) * len);
	if (!n)
		return (NULL);
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			n[i] = start;
			start++;
			i++;
		}
	}
	else
		while (start >= end)
		{
			n[i] = start;
			start--;
			i++;
		}
	return (n);
}
/*
int	main(void)
{
	int	*str;
	int	i;

	i = 0;
	str = ft_range(3, 8);
	while (i < 6)
	{
		printf("%d\n", str[i]);
		i++;
	}
	return (0);
}*/
