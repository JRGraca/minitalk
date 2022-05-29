# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbatista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 11:39:22 by jbatista          #+#    #+#              #
#    Updated: 2022/04/08 13:02:48 by jbatista         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./ft_printf.c ./ft_putchar_fd.c ./ft_putnbr_base.c ./ft_putstr_fd.c ./ft_putnbr_base.c ./ft_putunbr_base.c ./ft_strlen.c ./ft_putptr.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall

AR = ar rcs

RM = rm -rf

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(SRC) $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
