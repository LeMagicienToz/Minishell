/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:32 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/14 19:00:41 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# define DBQUOTECODE 34
# define QUOTECODE 39
# define DBQUOTE 0
# define QUOTE 1

typedef struct s_utils
{
	int		i;
	int		j;
	int		len;
	int		cmd;
	char	*res;
}	t_utils;

typedef struct s_data
{
	char	*input;
	char	*cmd;
	char	*settings;
	char	*args;
	t_utils	*u;
}	t_data;

void	wait_fork(pid_t child_pid);
void	fork_init(char **str, char **envp);
char	*ft_stripwhite(char *str);
int		ft_strlen_white(char *str);
int		ft_check_word(char *str);
int		get_cmd(char *str);
void	cmd_history(void);

//UTILS
void	ft_putnbr_base(int nb, int digit, char *base, int fd);
void	ft_printf_fd(int fd, char *str, ...);

//BUILT IN
void	ft_echo(char *str);

//PARSING
int		ft_strlen_without_quote(char *str);
char	*ft_get_cmd(char *input);
char	*ft_remove_space(char *str);
int		ft_len_space(char *str);
char	*ft_remove_cmd(char *input, int lencmd);
char	*ft_get_arg(t_utils *u, char *input, int lencmd);
char	*ft_init_res(t_utils *u, char *str);
void	ft_init_res_normed(t_utils *u, char *str, int code);
char	*ft_remove_quote(t_utils *u, char *str);
int		ft_check_quote(int i, char *str, int code);
void	ft_remove_quote_normed(t_utils *u, char *str, int code);

void	lol(int j, int v);
#endif