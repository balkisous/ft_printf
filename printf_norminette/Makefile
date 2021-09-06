# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:31:04 by bben-yaa          #+#    #+#              #
#    Updated: 2021/09/06 08:26:40 by bben-yaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		= ft_printf.c \
		  ft_putprint.c \
		  ft_print_and_size.c \
		  ft_leng_and_printtype.c \
		  ft_flag.c \
		  ft_speciaux_type.c \
		  ft_printftype.c \
		  ft_leng_and_printtype2.c\
		  ft_print_and_size2.c \

OBJ		= $(SRCS:.c=.o)
NAME		= libftprintf.a
RM		= /bin/rm -rf
CC		= clang
FLAGS		= -Wall -Wextra -Werror

%.o : %.c
		$(CC) -c $(FLAGS) $<

all:		$(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)
clean:
		$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re:	 fclean all
