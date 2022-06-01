/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:30:52 by jbatista          #+#    #+#             */
/*   Updated: 2022/06/01 14:23:58 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sig_handler(int sign)
{
	static char	c = -1;
	static int	pos = 0;

	if (sign == SIGUSR2)
		c ^= 128 >> pos;
	else if (sign == SIGUSR1)
		c |= 128 >> pos;
	pos++;
	if (pos == 8)
	{
		ft_printf("%c", c);
		pos = 0;
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
