# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 19:33:05 by aionescu          #+#    #+#              #
#    Updated: 2022/01/26 18:13:17 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft.a

SRC = pipex_main.c pipex_checkers.c pipex_utils.c

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) -Wall -Wextra -Werror $(SRC) $(LIBFT) -o $(NAME)
	rm -f *.o
	chmod a+x $(NAME)

$(LIBFT):
	cd libft && $(MAKE) fclean
	cd libft && $(MAKE)
	mv ./libft/libft.a libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
