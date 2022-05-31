/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:30:52 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/31 15:45:47 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sig_handler(int sign)
{
	static char	c = -1;
	static int	bits = 0;

	if (sign == SIGUSR2)
		c ^= 128 >> bits;
	else if (sign == SIGUSR1)
		c |= 128 >> bits;
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = -1;
	}
}

int	main(void)
{
	ft_printf("PID - %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
	}
}
