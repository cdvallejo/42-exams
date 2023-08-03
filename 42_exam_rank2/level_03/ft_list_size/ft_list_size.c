#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}					t_list;

int	ft_list_size(t_list *begin_list)
{
	int i;
	t_list *p;
	
	p = begin_list;
	i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
/*
int main()
{
	t_list list = {NULL, (void *)1};
	t_list list2 = {&list, (void *)5};
	t_list *list3 = &list2;
	int n;

	n = ft_list_size(list3);
	printf("%d", n);
}*/