#include "minitalk.h"

int	power(int base, int exp)
{
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	if (exp == 0)
		return (1);
	while (i++ <= exp)
		ret *= base;
	return (ret);
}

char	*binary2ascii(char	*binary)
{
	int	i;
	int	power2;
	char	temp;
	char	*result;
	int		byte;
	int		j;

	j = 0;
	i = 0;
	power2 = 7;
	byte = 0;
	result = malloc(10000);
	while (binary[i] != 0)
	{
		byte += (binary[i] - 48) * power(2, power2);
	//	printf(" byte - %d, power2 - %d, i - %d\n", byte, power2, i);
		power2--;
		i++;
		if (power2 < 0)
		{
			result[j] = byte;
			j++;
			power2 = 7;
			byte = 0;
		}
	}
	return (result);
}

int	main(void)
{
	printf("%s\n", binary2ascii("010011110010000001110010011000010111010001101111001000000111001001101111011001010111010100100000011000010010000001110010011011110110110001101000011000010010000001100100011000010010000001100111011000010111001001110010011000010110011001100001001000000110010001100101001000000111001001110101011011010010000001100100011011110010000001010010011001010110100100100000011001000110000100100000010100100111010101110011011100110110100101100001"));
}
