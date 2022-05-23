/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:54:13 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/23 13:17:18 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sig_handler(int signumber)
{
	if (signumber == SIGUSR1)
		printf("1");
	else if (signumber == SIGUSR2)
		printf("0");
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
