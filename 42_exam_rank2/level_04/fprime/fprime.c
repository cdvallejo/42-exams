#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		int n;
		n = atoi(av[1]);
		if (n == 1)
			printf("1");
		i = 2;
		while (n >= i)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n != i)
					printf("*");
				n = n / i;
				i--;
			}
			i++;
		}
	}
	printf("\n");
	return(0);
}
