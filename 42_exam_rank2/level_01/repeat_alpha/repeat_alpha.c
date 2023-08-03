#include <unistd.h> 

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s;
		int i;
		int count;

		s = av[1];
		i = 0;
		while (s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				count = (s[i] - 'a') + 1;
			else if (s[i] >= 'A' && s[i] <= 'Z')
				count = (s[i] - 'A') + 1;
			else
				write(1, &s[i], 1);
			while(count > 0)
			{
				write(1, &s[i], 1);
				count--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
