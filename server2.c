#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void	sig_handler(int	signum)
{

	printf("Signal received! - %d\n", signum);
	exit(1);
}

int	main(void)
{
	printf("PID - %d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, sig_handler);
		pause();
	}
}


