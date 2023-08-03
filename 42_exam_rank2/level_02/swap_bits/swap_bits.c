
//MODO 1

unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

//MODO 2

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	c;
	unsigned char	s;

	c = 0;
	s = 0;
    c = octet >> 4;
    s = (octet << 4) | c;
    return (s);
}

/*             1 = 00000001
swap debe dar 16 = 00010000*/
int	main(void)
{
	unsigned char	octet;

	octet = 1;
	printf("%d", swap_bits(octet));
}
