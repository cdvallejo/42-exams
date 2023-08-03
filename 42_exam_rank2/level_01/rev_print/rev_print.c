#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		char *sentence = av[1];
		i = 0;
		while (sentence[i])
			i++;
		i--;
		while (i >= 0)
		{
			write(1, &sentence[i], 1);
			i--;	
		}
	}
	write(1, "\n", 1);
}


