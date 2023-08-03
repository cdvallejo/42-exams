#include <unistd.h>

int	check_repeat(char *string, char s, int pos)
{
	int i;

	i = 0;
	while(i < pos)
	{
		if (string[i] == s)
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *s1;
		char *s2;
		int i;
		int j;
		int checks1;

		s1 = av[1];
		s2 = av[2];

		i = 0;
		while(s1[i])
		{
			if (check_repeat(s1, s1[i], i) == 1)
			{
				write(1, &s1[i], 1);
			}
			i++;
		}
		i = 0;
		while(s2[i])
		{
			j = 0;
			while(s1[j])
			{
				if (s1[j] == s2[i])
				{
					checks1 = 0;
					break ;
				}
				else
					checks1 = 1;
				j++;
			}
			if (check_repeat(s2, s2[i], i) == 1 && checks1 == 1)
			{
				write(1, &s2[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
