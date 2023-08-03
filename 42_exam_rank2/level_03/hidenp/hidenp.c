#include <unistd.h>

int ft_strlen(char *string)
{
	int i;

	i = 0;
	while(string[i])
		i++;
	return i;
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int i;
		int j;
		int check;
		char *s1;
		char *s2;

		s1 = av[1];
		s2 = av[2];

		i = 0;
		j = 0;
		check = 0;
		while (s1[i])
		{
			while (s2[j])
			{
				if (s2[j] == s1[i])
				{
					check++;
					break ;
				}
				j++;
			}
			i++;
		}
		if (check == ft_strlen(s1))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}
