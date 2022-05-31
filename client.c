/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:12:12 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/31 15:44:43 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

// SIGUSR1 = 1, SIGUSR2 = 0

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	j;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong number of parameters!");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		while (j < 8)
		{
			if (argv[2][i] & 128 >> j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		j = 0;
		i++;
	}
}
