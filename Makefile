# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uteza <uteza@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:29:49 by rperrin           #+#    #+#              #
#    Updated: 2022/11/09 14:58:46 by uteza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		Minishell

SRC=		main.c\
			libft/ft_strlen.c\
			libft/ft_putstr_fd.c \
			libft/ft_strlen.c \
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

LFLAGS=		-lreadline

CFLAGS	+=	-Wall -Wextra -Werror 

do:
			@make $(NAME)

$(NAME):		$(OBJ)
			$(CC) $(LFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)

all:			$(NAME)

clean:
			rm -f $(OBJ)
			rm -f *~ libft/*~

fclean:			clean
			rm -f $(NAME)

re:			fclean all
	