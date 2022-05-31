# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbatista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 16:14:38 by jbatista          #+#    #+#              #
#    Updated: 2022/05/31 15:40:17 by jbatista         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = client.c server.c minitalk_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = $(wildcard libft/*.c)

all: server client

server: server.o minitalk_utils.o libft 
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT) -Ilibft

client: client.o minitalk_utils.o libft
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT) -Ilibft

libft: ./libft
	make -C libft

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf client server minitalk.a libft/libft.a

re: fclean all

.PHONY = all re clean fclean libft
