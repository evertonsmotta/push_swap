# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 15:33:33 by evdos-sa          #+#    #+#              #
#    Updated: 2023/07/03 14:51:06 by evdos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
RM = rm -rf

SRCS = src/push_swap.c src/push_swap_utils.c\
	src/push.c src/reverse.c src/rotate.c src/swap.c src/sort_small.c\
	src/sort_medium.c src/get_value.c src/stack.c src/push_and_pop.c\
	src/step_zero.c src/step_one.c src/step_two.c src/step_three.c\
	src/step_four.c src/step_first_final.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS)
	
fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re