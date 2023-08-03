#include <unistd.h>

int check_repeat(char *string, char c, int pos)
{
    int i;

    i = 0;
    while(i < pos)
    {
        if (string[i] == c)
            return 0;
        i++;
    }
    return 1;
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char *s1;
        char *s2;
        int i;
        int j;

        s1 = av[1];
        s2 = av[2];
        i = 0;
        while(s1[i])
        {
            j = 0;
            while(s2[j])
            {
                if (s2[j] == s1[i])
                {
                    if ((check_repeat(s1, s2[j], i) == 1))
                    {
                        write(1, &s1[i], 1);
                        break ;
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
