# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agigi <agigi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 19:22:08 by agigi             #+#    #+#              #
#    Updated: 2020/11/11 20:25:19 by agigi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c			\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c		\
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_isalpha.c		\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c	\
		ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c			\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_itoa.c			\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c		\
		
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c		\
			ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c			\
			ft_lstdelone.c													\

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib ${NAME}
		gcc $(CFLAGS) -c $(SRCS) 
bonus:		$(NAME) $(OBJS_BONUS)
		ar rc $(NAME) $(OBJS_BONUS)
		ranlib ${NAME}

clean:
		rm -f ${OBJS} ${OBJS_BONUS}
fclean: clean
		rm -f ${NAME}
		
re: fclean all
