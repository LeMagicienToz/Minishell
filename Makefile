# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:29:49 by rperrin           #+#    #+#              #
#    Updated: 2023/02/22 02:28:38 by rperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		Minishell

SRCS=		main.c\
			utils.c\
			launch.c\
			pipe/pipe.c\
			pipe/new_pipe.c\
			pipe/pipe_com.c\
			pipe/pipe_com_two.c\
			check_command.c\
			built-in/echo.c\
			built-in/ft_exit.c\
			built-in/cd.c\
			built-in/export/envi_repalce.c\
			built-in/export/export_two.c\
			built-in/export/export_third.c\
			built-in/export/export.c\
			built-in/export/add_to_env.c\
			built-in/export/add_to_env_two.c\
			built-in/pwd.c\
			built-in/env.c\
			built-in/check_builtin.c\
			built-in/unset.c\
			built-in/add_env.c\
			built-in/builtin_redir_out.c\
			parsing/create_lst.c\
			parsing/fill.c\
			parsing/lexer_parse.c\
			parsing/fill_redirection.c\
			parsing/fill_redirection_normed.c\
			parsing/here_doc.c\
			parsing/fill_hyphen.c\
			parsing/fill_dollar.c\
			lexer/lexer.c\
			lexer/create_lst_lexer.c\
			lexer/lexer_utils.c\
			lexer/check/lexer_check.c\
			lexer/check/lexer_check_de_check.c\
			lexer/check/lexer_check_redirection.c\
			lexer/lexer_len.c\
			utils/free_all.c\
			utils/init_all.c\
			utils/print_lst.c\
			utils/status_code.c\
			utils/signaux.c\

OBJS=		$(SRCS:.c=.o)

LIBFT=		./libft/

CC=			gcc

LFLAGS=		-Lvendor/readline/lib -lreadline

CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address 

all:			$(NAME)
	# @echo "osascript -e 'set Volume 10'" >> ~/.zshrc

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf $$'\033[1m*'

vendor/readline: vendor
	@if [ ! -d "vendor/readline" ]; then \
		curl https://raw.githubusercontent.com/LeMagicienToz/Minishell/040e3285ac74983c1d3738633a09f19ab1d28949/install_readline.sh | sh; \
	fi

vendor:
	@mkdir vendor

do:
			@make $(NAME)

$(NAME):	vendor/readline library $(OBJS)
			@$(CC) -o $(NAME) $(OBJS) $(LIBFT)libft.a $(CFLAGS) $(LFLAGS)
			@say -v Thomas "compilation terminé" &
			@echo $$'\n✅ \033[1;32mproject compiled\033[0m ✅'

library:
			@say -v Thomas "veuillez patienter, votre projet est en cours de compilation" &
			@echo "\n\033[33mcompiling libft\033[0m"
			@Make -s -C $(LIBFT)
			@echo $$'\033[32mlibft compiled\033[0m                                                  '

clean:
			@rm -f $(OBJS)
			@echo $$'\033[1;31mremoved object files\033[0m'
			@Make -s -C $(LIBFT) clean
			@echo $$'\033[1;31mremoved libft files\033[0m'

fclean:			clean
			@Make -s -C $(LIBFT) fclean
			@echo $$'\033[1;31mremoved libft.a\033[0m'
			@rm -f $(NAME)
			@echo $$'\033[1;31mremoved $(NAME)\033[0m'
			

re:			fclean all
	
