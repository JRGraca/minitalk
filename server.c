/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:13:18 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/13 12:01:57 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signumber)
{
	if (signumber == SIGINT)
	{
		printf("Ctrl - C (signal %d) received - thanks for using Minitalk Server!\n", signumber);
		exit(1);
	}
	else if (signumber == SIGUSR1)
	{
		printf("USER SIGNAL (signal %d) RECEIVED! GREAT SUCCESS!!!!1!!!\n", signumber);
		exit(1);
	}
	else
	{
		printf("Unknown signal received (signal %d) - aborting...\n", signumber);
		exit(-1);
	}
}

int	main(void)
{
	printf("PID - %d\n", getpid());
	while(1)
	{
		signal(SIGINT, sig_handler);
		signal(SIGUSR1, sig_handler);
	}
}	
