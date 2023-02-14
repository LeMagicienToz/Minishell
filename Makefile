# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:29:49 by rperrin           #+#    #+#              #
#    Updated: 2023/02/13 09:21:14 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		Minishell

SRC=		main.c\
			utils.c\
			pipe/pipe.c\
			pipe/new_pipe.c\
			pipe/pipe_com.c\
			pipe/pipe_com_two.c\
			check_command.c\
			built-in/ft_exit.c\
			built-in/add_env.c\
			built-in/echo.c\
			built-in/builtin_redir_out.c\
			built-in/builtin_redir_in.c\
			built-in/cd.c\
			built-in/export/parcing_arg_exp.c\
			built-in/export/export.c\
			built-in/export/add_to_env.c\
			built-in/export/add_to_env_two.c\
			built-in/pwd.c\
			built-in/env.c\
			built-in/check_builtin.c\
			built-in/unset.c\
			parsing/getarg.c\
			parsing/create_lst.c\
			parsing/fill.c\
			parsing/lexer_parse.c\
			parsing/fill_redirection.c\
			parsing/here_doc.c\
			parsing/fill_hyphen.c\
			lexer/lexer.c\
			lexer/create_lst_lexer.c\
			lexer/lexer_utils.c\
			lexer/check/lexer_check.c\
			lexer/check/lexer_check_de_check.c\
			lexer/lexer_len.c\
			utils/free_all.c\
			utils/init_all.c\
			utils/print_lst.c\
			utils/status_code.c\
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
			libft/ft_isalnum.c \
			libft/ft_strcmp.c \
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
	