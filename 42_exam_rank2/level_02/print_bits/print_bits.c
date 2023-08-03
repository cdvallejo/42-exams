#include <unistd.h>

/*La base binaria son 8 números de 0 ó 1. Cada pos(desde la derecha) representa el doble del número anterior
empezando por 1:  "128 64 32 16 8 4 2 1". Cada posición será 1 si el número llega al valor que representa
o se pasa. Si no, será 0.

Con nuestra función, empezamos desde el 128 y comprobamos si el número es igual o mayor al dado (si es así será 1, si no 0),
e imprimimos. Si cabe tenemos que sacar el resto del octet dado por i. Y i se dividirá por 2 para pasar
a la siguiente ranura. OJO: Si es 0 no será necesario sacar el resto del octeto, simplemente con pasar
a la siguiente ranura. */

//MODO 1 - Con operadores

void	print_bits(unsigned char octet)
{
	unsigned int i;

	i = 8;
	unsigned char 	bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

//MODO 2 - Con operadores pero simplificado

void	print_bits(unsigned char octet)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if (octet >> i & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

// MODO 2 - Sin operadores

void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (octet >= i)
		{
			write(1, "1", 1);
			octet %= i;
            i /= 2;
		}
		else
		{
			write(1, "0", 1);
			i /= 2;
		}
	}
}

/*
int	main(void)
{
	unsigned char octet;

	octet = 128;
	print_bits(octet);
	return (0);
}*/
