#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include "includes/minitalk.h"

int	main(void)
{
	char	*pid;

	printf("PID - %u\n", getpid());
	pid = gets(stdin);
	kill(SIGUSR1, ft_atoi(pid));
i/*	while(1 == 1)
		signal(SIGUSR2, printf("Signal received!\n - %d"), signum);*/
}
