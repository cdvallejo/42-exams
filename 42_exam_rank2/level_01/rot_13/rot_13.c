#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		char *s = av[1];
		
		i = 0;
		while(s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'm' || s[i] >= 'A' && s[i] <= 'M')
				s[i] += 13;
			else if (s[i] >= 'n' && s[i] <= 'z' || s[i] >= 'N' && s[i] <= 'Z')
				s[i] -= 13;
			write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
