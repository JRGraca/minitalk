/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:32:40 by jbatista          #+#    #+#             */
/*   Updated: 2022/04/08 12:57:02 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

static char	*selectbase(char flag)
{
	if (flag == 'x' || flag == 'p')
		return ("0123456789abcdef");
	if (flag == 'X')
		return ("0123456789ABCDEF");
	if (flag == 'd' || flag == 'i' || flag == 'u')
		return ("0123456789");
	else
		return (NULL);
}

static int	writedata(int flag, va_list args)
{
	char	*base;

	base = selectbase(flag);
	if (flag == '%')
		return (ft_putchar_fd('%', 1));
	if (flag == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (flag == 'i' || flag == 'd')
		return (ft_putnbr_base(va_arg(args, int), base));
	if (flag == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (flag == 'p')
		return (ft_putstr_fd("0x", 1) + \
				ft_putptr(va_arg(args, unsigned long), base));
	if (flag == 'x')
		return (ft_putunbr_base(va_arg(args, unsigned long), base));
	if (flag == 'X')
		return (ft_putunbr_base(va_arg(args, unsigned long), base));
	if (flag == 'u')
		return (ft_putunbr_base(va_arg(args, unsigned long), base));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			count += writedata(format[i + 1], args);
			i++;
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
