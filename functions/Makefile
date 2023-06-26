# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarone <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 18:49:06 by gbarone           #+#    #+#              #
#    Updated: 2023/05/04 10:50:30 by gbarone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = functions.a

SRC = ft_printf.c\
ft_pp.c\
ft_ps.c\
ft_pu.c\
ft_putchar_fd.c\
ft_putnbr_base_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_pxup.c\
ft_pxdown.c\
ft_itoa.c\
ft_isdigit.c\
ft_atoi.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM = rm -f

all: ${NAME}

$(NAME): $(OBJ)
	ar -rcs ${NAME} ${OBJ}

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

