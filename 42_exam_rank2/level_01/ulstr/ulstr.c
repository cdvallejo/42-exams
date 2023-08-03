#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		char *s;

		s = av[1];
		i = 0;
		while(s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
			write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
