#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int	ft_atoi(char *string)
{
	int i;
	int result;
	int sign;

	i = 0;
	sign = 1;
	if (string[0] == '-')
	{
		sign = -1;
		i++;
	}
	result = 0;
	while (string[i])
	{
		result *= 10;
		result += string[i] - 48;
		i++;
	}
	return (result * sign);
}

int	ft_is_prime(int n)
{
	int i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i;
		int n;
		int sum;

		n = ft_atoi(av[1]);
		if (n > 0)
		{
			sum = 0;
			i = 2;
			while (i <= n)
			{
				if (ft_is_prime(i))
					sum += i;
				i++;
			}
			ft_putnbr(sum);
		}
		else
			write(1, "0", 1);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
