/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:18:01 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/23 17:05:35 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (argc != 3)
	{
		printf("Wrong number of parameters!");
		return (0);
	}
	pid = atoi(argv[1]);
	msg = argv[2];
	while (msg[++i] != 0)
	{
		while (j <= 7)
		{
			if ((msg[i] & power(2, (7 - j))))
				kill(pid, SIGUSR1);
			//	printf("1");
			else
				kill(pid, SIGUSR2);
//				printf("0");
			j++;
			usleep(80);
		}
		j = 0;
	}
}	
