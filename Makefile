# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:29:49 by rperrin           #+#    #+#              #
#    Updated: 2023/01/13 14:54:18 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		Minishell

SRC=		main.c\
			utils.c\
			cmd.c\
			pipe/pipe.c\
			pipe/pipe_com.c\
			pipe/pipe_com_two.c\
			check_command.c\
			built-in/echo.c\
			built-in/cd.c\
			built-in/export.c\
			built-in/pwd.c\
			built-in/env.c\
			built-in/check_builtin.c\
			parsing/getarg.c\
			parsing/remove_quote.c\
			parsing/remove_space.c\
			lexer/lexer_parse.c\
			lexer/lexer.c\
			lexer/create_lst.c\
			lexer/lexer_utils.c\
			lexer/lexer_check.c\
			lexer/lexer_len.c\
			lexer/ft_split_pipe.c\
			lol/lol.c\
			libft/ft_memcpy.c\
			libft/ft_isprint.c\
			libft/ft_lstsize.c\
			libft/ft_strcpy.c\
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
			libft/ft_strchr.c \
			libft/ft_atoi.c \
			libft/ft_itoa.c

OBJ=		$(SRC:.c=.o)

CC=			gcc

LFLAGS=		-l readline

CFLAGS	+=	-Wall -Wextra -Werror -g -fsanitize=address 

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
	