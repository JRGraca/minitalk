# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbatista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 17:20:53 by jbatista          #+#    #+#              #
#    Updated: 2022/05/12 17:24:32 by jbatista         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	cd libft && make all
#	cd includes && make all #
	gcc -Werror -Wextra -Wall client2.c -o client2
	gcc -Werror -Wextra -Wall server2.c -o server2

clean:
	rm -rf client2.o server2.o

fclean: clean
	rm client2.a
	rm server2.a
