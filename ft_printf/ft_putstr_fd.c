/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:31:23 by jbatista          #+#    #+#             */
/*   Updated: 2022/04/07 17:12:19 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_printf("(null)"));
	return (write(fd, s, ft_strlen(s)));
}
