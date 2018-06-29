#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kradoste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/02 19:35:36 by kradoste          #+#    #+#              #
#    Updated: 2018/05/05 18:49:53 by kradoste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CFLAG = -Wall -Werror -Wextra
SOURCE = *.c

all : $(NAME)

$(NAME) :
		make -C libft
		gcc -o $(NAME) $(CFLAG) $(SOURCE) -Llibft -lft -I fillit.h

.PHONY : clean fclean re

clean :
		make clean -C libft
		/bin/rm -f *~

fclean : clean
		make fclean -C libft
		/bin/rm -f $(NAME)

re : fclean all