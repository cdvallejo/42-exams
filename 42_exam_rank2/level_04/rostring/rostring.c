#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	str_len(char *string)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] <= 32)
			i++;
		else
		{
			while (string[i] > 32)
				i++;
			len++;
		}
	}
	printf("\nTiene %d palabras\n", len);
	return (len);
}

int	word_len(char *string, int i)
{
	int	count;
	int	j;

	j = i;
	while (string[j] <= 32 && string[j] != '\0')
		j++;
	count = 0;
	while (string[j] > 32 && string[j] != '\0')
	{
		count++;
		j++;
	}
	printf("\nTiene %d letras\n", count);
	return (count);
}

char	**ft_split(char *string)
{
	int		i;
	int		i2;
	int		i3;
	char	**split;

	split = (char **)malloc(sizeof(char *) * str_len(string) + 1);
	if (!split)
		return (0);
	i = 0;
	while (string[i] <= 32)
		i++;
	i2 = 0;
	while (string[i] != '\0')
	{
		if (string[i] > 32)
		{
			split[i2] = (char *)malloc(sizeof(char) * word_len(string, i) + 1);
			i3 = 0;
			while (string[i] > 32)
			{
				split[i2][i3] = string[i];
				i3++;
				i++;
			}
			split[i2][i3] = '\0';
			i2++;
		}
		else
			i++;
	}
	split[i2] = 0;
	return (split);
}

int	main(int ac, char **av)
{
	char	**s;
	int		i;

	if (ac >= 2)
	{
		s = ft_split(av[1]);
		i = 1;
		while (s[i] != 0)
		{
			putstr(s[i]);
			write(1, " ", 1);
			i++;
		}
		putstr(s[0]);
	}
	write(1, "\n", 1);
}
