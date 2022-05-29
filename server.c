/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:54:13 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/23 17:06:25 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
int	pos;
char	*bits;

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

char	*binary2ascii(char *binary)
{
	int	i;
	int	power2;
	int	byte;
	int	j;
	char	*result;

	j = 0;
	i = 0;
	power2 = 7;
	byte = 0;
	result = malloc(10000);
	while (binary[i] != 0)
	{
		byte += (binary[i] - 48) * power(2, power2);
		printf(" byte - %d, power2 - %d, i - %d\n", byte, power2, i);
		power2--;
		i++;
	}
	pause()
	if (power2 < 0)
	{
		result[j] = byte;
		j++;
		power2 = 7;
		byte = 0;
	}
	printf("%s\n", result);
	return (result);
}

void	sig_handler(int signumber)
{
	if (!pos)
		pos = 0;
	if (!bits)
		bits = malloc(1000);
	if (signumber == SIGUSR1)
		bits[pos] = 49;
	else if (signumber == SIGUSR2)
		bits[pos] = 48;
	pos++;
	printf("%s\n", binary2ascii(bits));
}

int	main(void)
{
	printf("PID - %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		write(1, "\n", 1);
		pause();
	}
}
