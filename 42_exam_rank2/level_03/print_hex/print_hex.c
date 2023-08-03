#include <unistd.h>

int	ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while(str[i])
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

char values[] = {'0', '1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

void print_hex(int dec, char *hex)
{
	int i = 0;

	while (dec > 15)
	{
		hex[i++] = values[dec % 16];
		dec = dec / 16;
	}
	hex[i++] = values[dec % 16];
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int dec;
		char hex[10] = {0};
		int i = 9;

		dec = ft_atoi(av[1]);
		if (dec == 0)
			write(1, "0", 1);
		else
		{
			print_hex(dec, hex);
			while (i >= 0 && hex[i] == 0)
				i--;
			while (i >= 0)
				write(1, &hex[i--], 1);
		}
	}
	write(1, "\n", 1);
}
