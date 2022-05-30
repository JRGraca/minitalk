/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:59:34 by jbatista          #+#    #+#             */
/*   Updated: 2022/05/30 16:02:56 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	power(int base, int exp)
{
	int	i;
	int	ret;

	i = 1;
	ret = 1;
	if (exp == 0)
		return (1);
	while (i++ <= exp)
		ret *= base;
	return (ret);
}
