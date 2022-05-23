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

void	sig_handler(int signumber)
{
	static int pos;
	static char	*bits;
	
	if (!pos)
		pos = 0;
	if (!bits)
		bits = malloc(1000);
	if (signumber == SIGUSR1)
		bits[pos] = 49;
	else if (signumber == SIGUSR2)
		bits[pos] = 48;
	pos++;
	printf("%s\n", bits);
}

int	main(void)
{
	printf("PID - %d\n", getpid());
	while (1 == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		write(1, "\n", 1);
		pause();
	}
}
