# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agigi <agigi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 17:12:07 by agigi             #+#    #+#              #
#    Updated: 2020/12/20 21:44:01 by agigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCDIR = ./src/
LIBFTDIR = ./libft/
INCLD = -I ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLD)
FILES_PRINTF = ft_printf_conver.c ft_printf_output.c ft_printf_parser.c		\
				ft_printf_utils.c ft_printf.c								\

FILES_LIBFT =	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c				\
				ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c			\
				ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c			\
				ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c			\
				ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c			\
				ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c				\
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c			\
				ft_strmapi.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c		\
				ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c					\
				ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c		\
				ft_lstadd_back.c ft_lstclear.c	ft_lstiter.c ft_lstdelone.c	\

SRC_PRINTF = $(addprefix $(SRCDIR), $(FILES_PRINTF))
SRC_LIBFT = $(addprefix $(LIBFTDIR), $(FILES_LIBFT))
OBJS_PRINTF = $(SRC_PRINTF:.c=.o)
OBJS_LIBFT = $(SRC_LIBFT:.c=.o)
OBJS = $(OBJS_PRINTF) $(OBJS_LIBFT)
all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib ${NAME}

clean:
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}

re: fclean all
