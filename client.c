/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:02:26 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/13 12:12:22 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		printf("Invalid number of arguments!");
		exit(-1);
	}
	else
	{
		pid = atoi(argv[1]);
		printf("Sending SIGUSR1 to pid %d\n", pid);
		kill(pid, SIGUSR1);
/*		kill(pid, SIGINT);*/
	}
}
