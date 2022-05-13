/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:13:45 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/12 15:21:13 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/minitalk.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	int	pid;

	if(argc != 3)
	{
		ft_printf("Argument format invalid!");
		return (-1);
	}
	pid = ft_atoi((const char)argv[1]);
	ft_printf("%d\n", pid);
}
