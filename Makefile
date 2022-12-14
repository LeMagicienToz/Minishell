# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:29:49 by rperrin           #+#    #+#              #
#    Updated: 2022/12/13 22:21:34 by rperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		Minishell

SRC=		main.c\
			utils.c\
			cmd.c\
			check_command.c\
			built-in/echo.c\
			parsing/getcmd.c\
			parsing/getarg.c\
			parsing/remove_quote.c\
			parsing/remove_space.c\
			lol/lol.c\
			libft/ft_bzero.c\
			libft/ft_strjoin.c\
			libft/ft_split.c\
			libft/ft_substr.c\
			libft/ft_isalpha.c\
			libft/ft_strlen.c\
			libft/ft_putstr_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_strncmp.c \
			libft/ft_putchar_fd.c \
			libft/ft_isdigit.c \
			libft/ft_strdup.c \
			libft/ft_atoi.c \
			libft/ft_itoa.c

OBJ=		$(SRC:.c=.o)

CC=			gcc

LFLAGS=		-l readline

CFLAGS	+=	-Wall -Wextra -Werror -g# -fsanitize=address 

do:
			@make $(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

all:			$(NAME)

clean:
			rm -f $(OBJ)
			rm -f *~ libft/*~

fclean:			clean
			rm -f $(NAME)

re:			fclean all
	