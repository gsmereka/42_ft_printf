# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 22:11:38 by lbiasuz           #+#    #+#              #
#    Updated: 2022/12/24 22:55:22 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	printf.a

CFLAGS		=	-Wall -Wextra -Werror

SRC_DIR		=	src

OBJ_DIR		=	./obj

SRC			=	ft_printf.c ft_strjoin.c ft_itoa.c ft_itohex.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c \
				ft_utoa.c ft_strchr.c ft_strlen.c ft_toupper.c

HEADER		=	./header/ft_printf.h

OBJ			=	$(addprefix $(OBJ_DIR)/, $(addprefix $(SRC_DIR)/, $(SRC:.c=.o)))

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)$(SRC_DIR)
	cc $(CFLAGS) -c $< -o $@ 

$(NAME): $(HEADER) $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
