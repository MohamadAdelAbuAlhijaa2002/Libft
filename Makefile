# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabualha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/24 19:40:36 by mabualha          #+#    #+#              #
#    Updated: 2026/09/24 19:52:15 by mabualha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = labft.a

CC = cc

CFLAGG = -Wall -Wextra -Werror

SRC = ft_strncmp.c ft_strnstr.c ft_strdup.c ft_memcpy.c ft_toupper.c \
ft_strchr.c ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strrchr.c \ 
ft_memcmp.c ft_isascii.c ft_isprint.c ft_strlcat.c ft_atoi.c \
ft_memchr.c ft_calloc.c ft_bzero.c ft_isalpha.c ft_isdigit.c\
ft_isalnum.c ft_memset.c ft_tolower.c

OBJ = $(SRC : .c = .o)

all: $(NAME)	

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(CFLAGG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclea: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
