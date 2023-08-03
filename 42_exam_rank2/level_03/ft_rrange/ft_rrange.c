#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
    int *rrange;
    int i;
    int count;

    count = (start - end) + 1;
    if (count < 0)
        count *= -1;
    rrange = (int *)malloc(sizeof(int));
    i = 0;
    while(end <= start)
    {
        rrange[i] = end;
        i++;
		end++;
    }
    while(end >= start)
    {
        rrange[i] = end;
        i++;
		end--;
    }
    return (rrange);
}
/*
int	main(void)
{
	int	*str;
	int	i;

	i = 0;
	str = ft_rrange(1, 3);
	while (i < 3)
	{
		printf("%d\n", str[i]);
		i++;
	}
	return (0);
}*/