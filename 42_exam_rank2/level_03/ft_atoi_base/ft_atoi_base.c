
int	check_str(int str_base)
{
	const char mask[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	return (mask[str_base - 1]);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int sign;
	int result;
	int i;
	char c;

	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	result = 0;
	while(str[i])
	{
		c = str[i];
		if (c >= 'A' && c <= 'F')
			 c += 32;
		if (c > check_str(str_base) || c < 48)
			break;
		if (c >= 'a' && c <= 'f')
			c -= 87;
		if (c >= '0' && c <= '9')
			c -= '0';
		result *= str_base;
		result += c;
		i++;
	}
	return (result * sign);
}
/*
int ac, char **av)
{
	int str_base;
	char *str;

	str_base = 16;
	str = "1a";
	printf("%d\n", ft_atoi_base(str, 16));
}*/
