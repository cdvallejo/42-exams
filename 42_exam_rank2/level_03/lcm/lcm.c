#include <stdio.h>

/*Queremos hayar el mínimo común múltiplo de  dos números dados. Para hacerlo, lcm parte del
número más grande de los dos, ya que es el que restringe la búsqueda (los números menores a este no no pueden dar nunca 0 como resto). 
Luego, en un while retornamos el primer número que dé módulo 0 en ambos números dados.*/
unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm;

	if (a == 0 || b == 0)
		return 0;
	if (a > b)
		lcm = a;
	else
		lcm = b;
	while (!(lcm % a == 0 && lcm % b == 0))
		lcm++;
	return (lcm);
}
/*
int main()
{
	unsigned int a = 3;
	unsigned int b = 8;

	printf("%d\n", lcm(a, b));
}*/
