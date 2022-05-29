/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:34:56 by jbatista          #+#    #+#             */
/*   Updated: 2022/04/08 12:55:53 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <limits.h>

static int	checkbase(char *base)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 1;
	while (base[i] != '\0')
	{
		while (base[i2] != '\0')
		{
			if (base[i] == base[i2])
				return (0);
			i2++;
		}
		i++;
		i2 = i + 1;
	}
	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base [i] > 126)
			return (0);
		i++;
	}
	return (1);
}

static int	write_number_in_base(unsigned long nbr, char *base, int basesize)
{
	unsigned int		n;
	char				a;
	int					count;

	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)basesize)
		count += write_number_in_base(n / basesize, base, basesize);
	a = base[n % basesize];
	count += write(1, &a, 1);
	return (count);
}

int	ft_putunbr_base(unsigned int nbr, char *base)
{
	int	basesize;
	int	count;

	count = 0;
	basesize = 0;
	if (checkbase(base) == 0)
		return (-1);
	while (base[basesize] != 0)
		basesize++;
	if (basesize < 2)
		return (-1);
	count += write_number_in_base(nbr, base, basesize);
	return (count);
}
