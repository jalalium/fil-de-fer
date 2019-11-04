# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Mokefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 21:00:25 by mmaaouni          #+#    #+#              #
#    Updated: 2018/10/23 18:29:20 by mmaaouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = *.c
OBJECTS = *.o

all: $(NAME)


$(NAME): $(OBJECTS)
	ar rc libft.a *.o
$(OBJECTS): $(FILES)
	gcc -Wall -Wextra -Werror -c $(FILES) includes/libft.h
clean:
	/bin/rm -f *.o
fclean: clean 
	/bin/rm -f libft.a
re: $(NAME)
