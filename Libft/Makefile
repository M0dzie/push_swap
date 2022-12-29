# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 13:07:05 by thmeyer           #+#    #+#              #
#    Updated: 2022/12/29 09:43:46 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

RM = rm -rf

SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_strdup.c \
	ft_calloc.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_itoa.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_printf.c \
	basic_ft.c \
	printnbr.c

SRCS_BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS = $(SRCS:%.c=objs/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=objs/%.o)
DIR_OBJS = objs/

all: directory $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

objs/%.o: %.c Makefile $(DIR_OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re bonus