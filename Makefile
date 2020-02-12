# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bruno <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 21:20:20 by bruno             #+#    #+#              #
#    Updated: 2018/12/03 14:39:06 by lvan-bei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

CC= gcc
CFLAGS= -Wall -Wextra -Werror
LIBFT= ./libft

objects	= read.o print.o tetriminos.o map.o solve.o valid_file.o solve_2.o main.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): lib $(objects)
	$(CC) $(CFLAGS) -o $@ $(objects) -L $(LIBFT) -lft

lib:
	make -C $(LIBFT) 
clean:
	make -C $(LIBFT) fclean
	rm -f $(objects)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean fclean     
