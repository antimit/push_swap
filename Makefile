# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antimit <antimit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 19:44:00 by antimit           #+#    #+#              #
#    Updated: 2024/10/19 19:44:20 by antimit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -I.

SRCS			= error_handle.c \
				  ft_split.c \
				  list.c \
				  main.c \
				  stack.c \
				  stack_functions.c \
				  sorting.c \
				  node_initialization.c \
				  push_swap.c \
				  word_process.c \
				  push_and_rotate.c \
				  swap_and_rotate.c

OBJS			= $(SRCS:.c=.o)

NAME			= program

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
