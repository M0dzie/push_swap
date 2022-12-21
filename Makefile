# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:35:55 by thmeyer           #+#    #+#              #
#    Updated: 2022/12/21 11:55:32 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

RM = rm -rf

SRCS = swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		push_swap.c

OBJS = $(SRCS:%.c=objs/%.o)
DIR_OBJS = objs/
LIBFT_OBJS = Libft/objs

all: $(NAME)

$(NAME): directory rsc $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

rsc:
	$(MAKE) -C Libft/

objs/%.o: %.c Makefile $(DIR_OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	$(RM) $(DIR_OBJS)
	$(RM) $(LIBFT_OBJS)
    
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C Libft/ clean

re: fclean
	$(MAKE) all
	$(MAKE) -C Libft/ fclean

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re