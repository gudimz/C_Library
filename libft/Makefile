# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agigi <agigi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 19:22:08 by agigi             #+#    #+#              #
#    Updated: 2020/11/01 19:18:19 by agigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)
clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
		
re: fclean all
