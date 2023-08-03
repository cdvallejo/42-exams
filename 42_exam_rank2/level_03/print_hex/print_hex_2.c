#include <unistd.h>

int	ft_atoi(char *str)
{
	int i;
	int  result;

	i = 0;
	result = 0;
	while(str[i])
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

void	print_hex(int dec)
{
	if (dec >= 16)
		print_hex(dec / 16);
	write(1, &"0123456789abdcef"[dec % 16], 1);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		print_hex(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
}
