int		max(int* tab, unsigned int len)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	
	while(i < len)
	{
		if (tab[i] > count)
		{
			count = tab[i];
		}
		i++;
	}
	return count;
}

