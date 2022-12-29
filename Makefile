# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:35:55 by thmeyer           #+#    #+#              #
#    Updated: 2022/12/29 15:41:12 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		main.c

OBJS = $(SRCS:%.c=objs/%.o)
DIR_OBJS = objs/
LIBFT = Libft/

all: $(NAME)

$(NAME): directory rsc $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libft.a

rsc:
	$(MAKE) -C $(LIBFT)

objs/%.o: %.c Makefile $(DIR_OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	$(RM) $(DIR_OBJS)
	$(MAKE) clean -C $(LIBFT)
    
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re: fclean
	$(MAKE) all
	$(MAKE) all -C $(LIBFT)

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re