# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:35:55 by thmeyer           #+#    #+#              #
#    Updated: 2022/12/20 14:44:05 by thmeyer          ###   ########.fr        #
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
		reverse_rotate.c

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
	$(MAKE) clean -C Libft/

re: fclean
	$(MAKE) all
	$(MAKE) fclean -C Libft/

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re