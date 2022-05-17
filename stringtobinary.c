//test file DO NOT SHIP!
//
#include "minitalk.h"
#include <stdlib.h>

int	ft_nbrlen(unsigned int	nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return(1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}
int	main(void)
{
	/*char	c;
	int		cint;
	char	*bin;
	int		i;

	i = 0;
	c = 'a';
	cint = 10;
	printf("%d\n", cint);
	bin = malloc(10000);
	while (cint != 0)
	{
		printf("Working\n");
		if(cint % 2 == 0)
			bin[i] = '0';
		else
		{
			printf("Still working\n");
			bin[i] = '1';
			printf("After writing\n");
		}
		printf("In while loop - %s\n", bin);
		i++;
		cint = cint / 2;
	}
	printf("Binary - %s\n", bin);
	free(bin);
	*/
	printf("%d\n", ft_nbrlen(1234567));
}
