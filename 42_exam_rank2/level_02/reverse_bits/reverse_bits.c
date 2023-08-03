#include <stdio.h>

//MODO 1

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r = 0;
	int				i;

	i = 0;
	while (i < 8)
	{
		r = (r << 1) | ((octet >> i) & 1);
		i++;
	}
	return (r);
}

//MODO 2

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	c = 0;
	unsigned char	r = 0;
	int				i;

	i = 0;
	while (i < 8)
	{
		c = (octet >> i) & 1;
		r = r << 1 | c;
		i++;
	}
	return (r);
}
/*
int	main(void)
{
	unsigned char octet;

	octet = 1;
	printf("%d", reverse_bits(octet));
}*/
