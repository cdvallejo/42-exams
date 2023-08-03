#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
        ft_putchar(nb + '0');
}

int ft_atoi(char *str)
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

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i;
        int n;
        
        n = ft_atoi(av[1]);
        i = 1;
        while(i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(n);
            write(1, " = ", 3);
            ft_putnbr(i * n);
            if (i < 9)
                write(1, "\n", 1);
            i++;
        }
    }
    write(1,"\n", 1);
}
