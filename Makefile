# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:35:55 by thmeyer           #+#    #+#              #
#    Updated: 2022/12/20 11:28:12 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = 

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

RM = rm -rf

SRCS = 

OBJS = $(SRCS:%.c=objs/%.o)

all: directory rsc $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

rsc:
	$(MAKE) -C Libft

objs/%.o: %.c Makefile objs $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	$(RM) objs
	$(RM) Libft/objs
    
fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

directory:
	@mkdir -p objs

.PHONY: all clean fclean re