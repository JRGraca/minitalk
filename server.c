/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:30:52 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/30 17:37:06 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	sig_handler(int sign)
{
	char	*ret;

	ret = malloc(1000);
	ft_printf("Signal received - %d\n", sign);
	pause();
}
int	main(void)
{
	ft_printf("PID - %d\n", getpid());
	while(1)
		signal(SIGUSR1, sig_handler);
}
