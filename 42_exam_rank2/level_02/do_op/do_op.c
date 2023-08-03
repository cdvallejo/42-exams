#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
   	if (ac == 4)
    {
		int result;
        int n1;
        int n2;
        char sign;

        n1 = atoi(av[1]);
        n2 = atoi(av[3]);
        sign = av[2][0];
        result = 0;
        if (sign == '*')
            result = n1 * n2;
        else if (sign == '/')
            result = n1 / n2;
        else if (sign == '-')
            result = n1 - n2;
        else if (sign == '+')
			result = n1 + n2;
		else if (sign == '%')
			result = n1 % n2;
		printf("%d", result);
    }
    printf("\n");
	return (0);
}
