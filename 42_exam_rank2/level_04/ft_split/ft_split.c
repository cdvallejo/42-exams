#include <stdio.h>
#include <stdlib.h>

//Función para contar las palabras que hay en str
int	ft_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] <= 32)
			i++;
		while (str[i] > 32)
			i++;
		count++;
	}
	//printf("Tiene %d palabras\n", count);
	return (count);
}

//Función para contar las letras que tiene cada palabra, usamos static int
//para guardar el valor del recorrido en str
int	ft_word(char *string, int pos)
{
	int	count;
	int	j;

	j = pos;
	while (string[j] <= 32)
		j++;
	count = 0;
	while (string[j] > 32)
	{
		count++;
		j++;
	}
	//printf("\nTiene %d letras\n", count);
	return (count);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count(str) + 1));
	if (!split)
		return 0;
	while (str[i] <= 32 && str[i])
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			y = 0;
			split[j] = (char *)malloc(sizeof(char) * (ft_word(str, i) + 1));
			while (str[i] > 32)
			{
				split[j][y] = str[i];
				i++;
				y++;
			}
			split[j][y] = '\0';
			j++;
		}
		else
			i++;
	}
    split[j] = 0;
	return (split);
}
/*
int	main(int ac, char **av)
{
	char	**tab;
	int		count;

	if (ac == 2)
	{
		count = 1;
		tab = ft_split(av[1]);
		while (tab[count])
		{
			ft_putstr(tab[count]);
			write(1, " ", 1);
			count++;
		}
		ft_putstr(tab[0]);
	}
	write(1, "\n", 1);
}*/
