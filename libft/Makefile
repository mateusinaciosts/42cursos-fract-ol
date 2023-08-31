# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 10:36:18 by matsanto          #+#    #+#              #
#    Updated: 2023/05/26 14:47:25 by matsanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./libft


FLAGS = -Wall -Werror -Wextra

SOURCES			= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
					ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
					ft_memcpy.c ft_memmove.c ft_memset.c ft_strnstr.c ft_strchr.c\
					ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
					ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c\
					ft_strtrim.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_putchar_fd.c\
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c
					
						

OBJ = $(SOURCES:%.c=%.o)

all: ${NAME}
${NAME}:	${OBJ}
	ar -rcs ${NAME} ${OBJ}

%.o:	%.c
	cc $(FLAGS) -I ${HEADER} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all


