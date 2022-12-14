/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:32 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/01/12 13:20:00 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# define FTSTDOUT 1
# define FTSTDIN 0
# define DBQUOTECODE 34
# define QUOTECODE 39
# define SPACECODE 32
# define HYPHENCODE 45
# define QUOTECODE 39
# define PIPE 124
# define OUT 62

typedef struct s_utils
{
	int		i;
	int		j;
	int		len;
	int		cmd;
	char	*res;
}	t_utils;

typedef struct s_lst	t_lst;
struct s_lst
{
	char	*content;
	int		index;
	char	*out;
	char	*in;
	t_lst	*next;
	t_lst	*prev;
};

typedef struct s_data
{
	char	*input;
	char	**str;
	char	**command;
	int		fd[2][2];
	pid_t	*id;
	char	*path;
	char	*path_sec;
	char	*cmd;
	char	*settings;
	char	*args;
	char	*errorlexer;
	char	**lexer;
	char	*out;
	char	*in;
	int		maxindex;
	int		pipe;
	char	**envp;
	t_utils	*u;
	t_lst	*first;
	t_lst	*last;
}	t_data;

typedef struct s_built
{
	char	**tab_exp;
	char	**str;
	char	*save;
}	t_built;

void	wait_fork(pid_t child_pid);
void	fork_init(char **str, char **envp);
void	tiensmax(t_lst *lst, t_data *data);
char	*ft_stripwhite(char *str);
int		ft_strlen_white(char *str);
int		ft_check_word(char *str);
int		get_cmd(char *str);
void	cmd_history(void);
int		ft_lstsize(t_lst *lst);

//PIPE

void	init_pipe(t_lst *lst, t_data *data);
void	fork_maker(t_lst *lst, t_data *data);
char	**check_pipe(t_lst *lst, t_data *data);
void	pipe_com(t_lst *lst, t_data *data);
void	pipex_mod(t_data *data, int i, t_lst *lst);
char	*get_path(char **envp, char *arg);
void	put_lst_in_tab(t_data *data, int i, t_lst *lst);

//UTILS
void	ft_putnbr_base(int nb, int digit, char *base, int fd);
void	ft_printf_fd(int fd, char *str, ...);
int		ft_is_space(char c);
void	print_lst(t_lst *lst);

//BUILT IN
void	ft_echo(char *str);
void	ft_pwd(t_built *builtin);
void	ft_export(t_built *builtin, char **envp);
void	ft_env(t_built *builtin, char **envp);
int		check_builtin(char *command_buffer, char **envp, t_built	*builtin);
void	ft_cd(char *name, t_built *builtin);

//PARSING
char	*ft_remove_space(char *str);
int		ft_len_space(char *str);
char	*ft_remove_cmd(char *input, int lencmd);
char	*ft_get_arg(t_utils *u, char *input, int lencmd);
char	*ft_init_res(t_utils *u, char *str);
void	ft_init_res_normed(t_utils *u, char *str, int code);
char	*ft_remove_quote(t_utils *u, char *str);
int		ft_check_quote(int i, char *str, int code);
void	ft_remove_quote_normed(t_utils *u, char *str, int code);

//LEXER
t_lst	*detect_token(t_data *data, t_lst *lst, char *str);
t_lst	*detect_token_split(t_data *data, t_lst *lst, int *i);
int		get_len_token(char *str, int i, char last, t_data *data);
int		get_len_token_spacecode(char *str, int i, char last, t_data *data);
int		get_len_token_quote(char *str, int i, char last);
int		get_len_token_arg(char *str, int i, t_data *data);
void	create_token(t_data *data, t_lst **lst, char *str, int i);
void	addback(t_lst *node, t_lst **lst);
t_lst	*create_node(t_data *data, char *str);
int		check_separator(char c);
int		check_redirection(char *str, int i, t_data *data);
char	*fill_in(char *str, int i);
char	*fill_out(char *str, int i);
int		check_pipe_lexer(char **lexer, t_data *data);
void	fill_data_in(char *str, int i, char last, t_data *data);
char	*fill_token(char *str, int *i, int len, char last);
int		check_lexer_error(char *error);
int		check_no_space(char *str, int i, t_data *data);
char	**ft_split_pipe(const char *s, char c, t_data *data);

void	lol(int j, int v);
#endif