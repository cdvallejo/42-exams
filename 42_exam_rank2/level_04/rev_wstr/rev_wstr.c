#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	word_count(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		while (string[i] <= 32)
			i++;
		while (string[i] > 32)
			i++;
		count++;
	}
	return (count);
}

int	word_len(char *string, int pos)
{
	int i;

	i = pos;
	while (string[i] > 32 && str[i])
		i++;
	return (i);
}

char	**ft_split(char *string)
{
	char	**s;
	int		i;
	int		i2;
	int		i3;

	s = (char **)malloc(sizeof(char *) * word_count(string) + 1);
	if (!s)
		return (0);
	i = 0;
	while (string[i] <= 32)
		i++;
	i2 = 0;
	while (string[i])
	{
		if (string[i] > 32)
		{
			s[i2] = (char *)malloc(sizeof(char) * word_len(string, i) + 1);
			if (!s[i2])
				return (0);
			i3 = 0;
			while (string[i] > 32)
			{
				s[i2][i3] = string[i];
				i++;
				i3++;
			}
			s[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	s[i2] = 0;
	return (s);
}

int	main(int ac, char **av)
{
	char **s;
	int i;

	if (ac == 2)
	{
		s = ft_split(av[1]);
		i = word_count(av[1]);
		i--;
		while (s[i] > 0)
		{
			ft_putstr(s[i]);
			write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
}