/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbatista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:47:51 by jbatista          #+#    #+#             */
/*   Updated: 2022/04/08 12:54:43 by jbatista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>

int		ft_printf(const char	*format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putunbr_base(unsigned long nbr, char *base);
int		ft_putptr(unsigned long nbr, char *base);
size_t	ft_strlen(const char *s);
#endif
