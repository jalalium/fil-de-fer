# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 22:30:43 by mmaaouni          #+#    #+#              #
#    Updated: 2019/01/15 22:36:43 by mmaaouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FILES = srcs/*.c
LIB = libft/libft.a
DIR = libft

all: $(NAME)

$(NAME): $(LIB)
		gcc -Wall -Wextra -Werror -I ../includes/fdf.h -I /usr/local/include $(FILES) $(LIB) -L /usr/local/lib/ -lmlx -framework OpenGL -framework Appkit -o $(NAME)
$(LIB):
		make -C $(DIR) re
clean:
		make -C $(DIR) clean
fclean: clean
		rm -f $(NAME)
		make -C $(DIR) fclean
re: fclean $(NAME)
