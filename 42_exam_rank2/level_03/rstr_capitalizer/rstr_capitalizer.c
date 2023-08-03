#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	char *s;
	int count;

	count = 1;
	if (ac >= 2)
	{
		while(count <= ac - 1)
		{
			s = av[count];
			i = 0;
			while(s[i])
			{
				if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] <= 32)
					s[i] -= 32;
				else if ((s[i] >= 'A' && s[i] <='Z') && s[i + 1] > 32)
					s[i] += 32;
				write(1, &s[i], 1);
				i++;
			}
			write(1, "\n", 1);
			count++;
		}	
	}
	else
		write(1, "\n", 1);
}
