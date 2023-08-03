#include <unistd.h>

int main(int ac, char **av)
{
	char *s = av[1];
	int i;

	i = 0;
	if(ac == 2)
	{
		while(s[i])
		{
			if (s[i -1] == '_')
			{	
				s[i] -= 32;
				write(1, &s[i], 1);
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
				write(1, &s[i], 1);
			i++;
		}	
	}
	write(1, "\n", 1);

}
