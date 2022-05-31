# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbatista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:14:38 by jbatista          #+#    #+#              #
#    Updated: 2022/05/31 15:31:43 by jbatista         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = client.c server.c minitalk_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: server client

server: server.o minitalk_utils.o libft minitalk_a
	$(CC) -o $@ $< -Ilibft

client: client.o minitalk_utils.o libft minitalk_a
	$(CC) -o $@ $< -Ilibft

libft: ./libft
	make -C libft

minitalk_a:
	ar rcs minitalk.h


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf client server minitalk.a libft/libft.a

re: fclean all

.PHONY = all re clean fclean libft
