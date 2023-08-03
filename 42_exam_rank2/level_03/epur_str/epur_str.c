#include <unistd.h>

int main(int ac, char **av)
{
	
	if (ac == 2)
	{
		char *s = av[1];
		int i;

		i = 0;
		while(s[i])
		{
			if (s[i] > 32)
				write(1, &s[i], 1);
			else if ((s[i] <= 32 && s[i + 1] > 32) && i != 0)
				write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
