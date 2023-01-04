# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:35:55 by thmeyer           #+#    #+#              #
#    Updated: 2023/01/04 13:07:04 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address

RM = rm -rf

SRCS = swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		parsing.c \
		fill_stack.c \
		sorting_small_amount.c \
		main.c

OBJS = $(SRCS:%.c=objs/%.o)
DIR_OBJS = objs/
LIBFT = Libft/
LIBFT_A = Libft/libft.a

all: directory rsc $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)

rsc:
	$(MAKE) -C $(LIBFT)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(DIR_OBJS)%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(DIR_OBJS)
    
fclean: 
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) clean
	$(RM) $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re