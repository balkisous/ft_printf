# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:31:04 by bben-yaa          #+#    #+#              #
#    Updated: 2021/06/23 12:14:54 by bben-yaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_function_1.c ft_function_2.c ft_function_3.c \
	   ft_function_4.c ft_function_6.c
OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a
RM = /bin/rm -rf
CC = clang
FLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) -c $(FLAGS) $<

all: $(NAME)

$(NAME): $(OBJ)
				ar -rcs $(NAME) $(OBJ)
clean:
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re = flean all
