# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sapark <sapark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 17:01:45 by sapark            #+#    #+#              #
#    Updated: 2019/06/24 20:25:34 by sapark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC=$(wildcard src/*.c)
CC=gcc -g -fsanitize=address
# CC=gcc list.c -g -fsanitize=address
CFLAGS=-Wall -Wextra -Werror -Iincludes
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC)
	cd src/libft && make -f Makefile
	mv src/libft/libft.a .
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) libft.a

clean:
	-cd src/libft && make clean

fclean: clean
	-cd src/libft && make fclean
	-rm -f $(NAME) 
	-rm -f libft.a

re: fclean $(NAME)

.PHONY: clean fclean re