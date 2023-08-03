#include <stdlib.h>

int main(int ac, char** av)
{
	if (ac == 3)
	{
		unsigned int pgcd;
		unsigned int a;
		unsigned int b;
		int i;

		a = atoi(av[1]);
		b = atoi(av[2]);
		pgcd = 1;
		i = 1;
		while(i <= a && i <= b)
		{
			if (a % i == 0 && b % i == 0)
				pgcd = i;
			i++;
		}
		printf("%d",pgcd);

	}
	printf("\n");
}
