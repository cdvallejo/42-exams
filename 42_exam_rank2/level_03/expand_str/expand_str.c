#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i;
        char *s = av[1];

        i = 0;
		if (s[i] == 0)
		{
			write(1, "\n", 1);
			return 0;
		}
		while(s[i] <= 32)
			i++;
        while(s[i])
        {
            if (s[i] <= 32 && s[i + 1] > 32)
                write(1, "   ", 3);
            else if (s[i] > 32)
                write(1, &s[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
