#include "list.h"
#include <stdlib.h>

/*Esta función pasa por parámetro otra en la que compara dos int de una lista y comprueba si están ordenados.
Para ello se necesita crear una lista temporal que duplica la original, para tener siempre la referencia al primer 
nodo de la lista original. Por eso, al final, cuando ya está ordenada la lista, ésta se equipara a la temporal 
para tener la referencia al primer nodo, que es lo que la función tiene que devolver.*/

int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*temp;
	int		swap;

	temp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = temp;
		}
		else
			lst = lst->next;
	}
	lst = temp;
	return (lst);
}

/*Una lista necesita para recorrerse un puntero que apunte a ella, si no no podemos acceder a ella.
Por eso es necesario la t_list *result, que apuntará a value3 para ir pasando de un nodo a otro.*/

//Main MODO 1: creando una lista puntero para apuntar a value3.
int	main(void)
{
	t_list	value1 = {8, NULL};
	t_list	value2 = {5, &value1};
	t_list	value3 = {7, &value2};
	t_list *result = &value3;

	sort_list(result, &ascending);
	while (result)
	{
		printf("%d\n", result->data);
		result = result->next;
	}
}

//Main MODO 2: creando una lista puntero para introducir los datos para apuntar a value3.
int	main(void)
{
	t_list	value1 = {8, NULL};
	t_list	value2 = {5, &value1};
	t_list	*value3 = malloc(sizeof(int) * 3);

	value3->data = 7;
	value3->next = &value2;
	sort_list(value3, &ascending);
	while (value3)
	{
		printf("%d\n", value3->data);
		value3 = value3->next;
	}
}
