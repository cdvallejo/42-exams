#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	if (ac == 2)
	{
		char *s = av[1];
		i = 0;
		while (s[i] != '\0')
			i++;
		i--;
		while (s[i] <= 32)
			i--;
		while(s[i] > 32)
			i--;
		i++;
		while (s[i] > 32)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
