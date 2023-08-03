#include <unistd.h>

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		int arg;
		int i;
		int c;
		char *s;

		arg = ac - 1;
		c = 1;
		while(c <= arg)
		{
			s = av[c];
			i = 0;
			while(s[i])
			{
				if((s[i - 1] <= 32 && s[i] >= 'a' && s[i] <= 'z') || s[i] == 0) 
					  s[i] -= 32;	
				else if ((s[i] >= 'A' && s[i] <= 'Z') && (s[i - 1] > 32))
					s[i] += 32;
				write(1, &s[i], 1);
				i++;
			}
			write(1, "\n", 1);
			c++;
		}
	}
	else
		write(1, "\n", 1);
}
