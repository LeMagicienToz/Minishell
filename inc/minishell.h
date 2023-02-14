/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:32 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/02/14 03:31:03 by muteza           ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/uio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# define FTSTDOUT 1
# define FTSTDIN 0
# define DBQUOTECODE 34
# define SPACECODE 32
# define HYPHENCODE 45
# define QUOTECODE 39
# define PIPECODE 124
# define OUTCODE 62
# define INCODE 60
# define DOLLARCODE 36
# define EQUALCODE 61
# define HYPHEN 409
# define DBQUOTE 410
# define QUOTE 411
# define ROUT 412
# define DBROUT 413
# define RIN 414
# define DBRIN 415
# define TEXT 416
# define PIPE 417
# define SPACE 418
# define DOLLAR 419

typedef struct s_utils
{
	int		i;
	int		j;
	int		len;
	int		cmd;
	char	*res;
}	t_utils;

typedef struct s_lexer	t_lexer;
struct s_lexer
{
	char	*content;
	int		type;
	int		index;
	t_lexer	*next;
	t_lexer	*prev;
};

typedef struct s_lst	t_lst;
struct s_lst
{
	char	*content;
	int		index;
	int		fdout;
	int		fdin;
	int		typeout;
	int		n;
	int		null;
	t_lst	*next;
	t_lst	*prev;
};

typedef struct s_data
{
	int		err_val;
	int		ex_ind;
	char	*input;
	int		sv;
	char	**str;
	char	**command;
	int		ret;
	int		save;
	char	*save_builtin;
	int		fd[2];
	pid_t	id;
	char	*path;
	char	**exp;
	char	*cmd;
	char	*settings;
	char	*args;
	char	*errorlexer;
	char	**lexer;
	int		out;
	int		in;
	int		maxindex;
	int		pipe;
	char	**envp;
	int		typeout;
	int		checkexport;
	int		status;
	char	**errors;
	int		k;
	int		n;
	int		stopn;
	int		heredoc;
	int		check;
	int		hyphen;
	int		x;
	int		null;
	t_lst	*env;
	t_lst	*export;
	t_utils	*u;
}	t_data;

void	clavier_int(int sig_num);
void	wait_fork(pid_t child_pid);
void	tiensmax(t_lst *lst, t_data *data);
char	*ft_stripwhite(char *str);
int		ft_strlen_white(char *str);
int		ft_check_word(char *str);
int		get_cmd(char *str);
void	cmd_history(void);
int		ft_lstsize(t_lst *lst);

//REDIRECTION
int		check_redir(t_data *data, t_lst *lst);
void	exp_redir(t_data *data, t_lst *lst);
void	pwd_redir(t_data *data, t_lst *lst);
void	env_redir(t_data *data, t_lst *lst);
void	echo_redir(t_data *data, t_lst *lst);

//PIPE
int		add_to_export(t_data *data);
void	last_pipe_command(t_data *data, t_lst *tmp, int i);
void	init_pipe(t_lst *lst, t_data *data);
void	fork_maker(t_lst *lst, t_data *data);
void	more_pipe(t_data *data, t_lst *lst);
void	no_more_command(t_data *data, t_lst *lst);
char	**check_pipe(t_lst *lst, t_data *data);
void	pipe_com(t_lst *lst, t_data *data);
void	pipex_mod(t_data *data, int i, t_lst *lst, int k);
char	*get_path(char **envp, char *arg, t_data *data);
void	put_lst_in_tab(t_data *data, t_lst **lst);
int		make_pipe(int i, t_data *data);

//UTILS
void	erreur_status(int status, char *error, t_data *data, int ex);
void	ft_putnbr_base(int nb, int digit, char *base, int fd);
void	ft_printf_fd(int fd, char *str, ...);
int		ft_is_space(char c);
int		ft_str_is_space(char *str);
void	print_lst(t_lst *lst);
void	free_lst(t_lst **lst);
void	free_lex(t_lexer **lex);
void	free_data(t_data *data);
void	free_data_str(char **lol);
void	free_all(t_data *data, t_lexer **lex, t_lst **lst);
void	init_data(t_data *data, char **envp);
void	init_lst(t_lst **lst);
void	init_lex(t_lexer **lex);
void	init_exp(t_data *data);
void	status_init(t_data *data);

//BUILT IN

void	ft_exit(t_data *data);
void	normed_add_to_env(t_data *data, char *str);
void	normed_add_to_export(int i, t_data *data, char *str);
int		check_ex_env(t_lst *tmp, char *check);
int		check_ex_exp(t_lst *tmp, char *check);
int		check_equal_env(t_data *data);
int		builtin_pipe(t_data *data, t_lst *lst);
int		check_is_builtin(char *str);
void	add_to_env(t_data *data);
void	ft_echo(t_data *data, t_lst *lst);
void	ft_pwd(t_data *data, t_lst *lst);
int		ft_unset(t_data *data);
int		check_equal(t_data *data);
void	ft_export(t_data *data, t_lst *lst);
void	ft_env(t_data *data, t_lst *lst);
void	get_all_arg_exp(t_data *data);
int		ft_cd(t_data *data, t_lst *lst);
int		check_exicting_exp(t_data *data, char *str);
int		check_exicting_env(t_data *data, char *str);
void	replace_export(t_data *data, int x, char *add);
void	add_with_no_egual(t_data *data);
int		parcing_export(t_data *data);
int		builtin_no_pipe(t_data *data, t_lst *lst);

//PARSING
int		parc_export(t_data *data, char *str);
char	*get_env(t_data *data, char	*str);
int		ft_strlen_without_quote(char *str);
char	*ft_get_cmd(char *input);
char	*ft_remove_cmd(char *input, int lencmd);
char	*ft_get_arg(t_utils *u, char *input, int lencmd);
void	here_doc(char *end, t_data *data);
char	*here_doc_normed(char *res, char *tmp, char *read, char *end);
char	*fill_end(char *str, int len, int i);
char	*fill_here_doc(char *str);
char	*fill_hyphen(t_lexer **lex, t_data *data, char *res);
void	fill_hyphen_norm(t_lexer *tmp, t_data *data);
char	*fill_hyphen_join(t_lexer **lex, char *res);
char	*fill_hyphen_normed(t_lexer **lex, t_data *data, char *res);
int		check_here_doc(char *str, t_data *data);

//LEXER
void	create_token(t_data *data, t_lst **lst, char *str, int i);
void	addback(t_lst *node, t_lst **lst);
t_lst	*create_node(t_data *data, char *str);
int		check_separator(char c);
int		check_redirection(char c);
int		check_pipe_lexer(char *str, t_data *data);
int		check_pipe_lexer_normed(char *str, t_data *data);
void	fill_data_in(char *str, int i, char last, t_data *data);
int		check_lexer_error(char *str, t_data *data);
char	*ft_get_redirection(t_data *data, char *str);
int		check_quote(char *str, t_data *data);
char	*strdup_token(int len);
t_lexer	*create_node_lexer(char *str, int type);
void	addback_lexer(t_lexer *node, t_lexer **lst);
t_lexer	*create_lexer(t_lexer *lex, char *str);
void	create_token_lexer(t_lexer **lst, char *str, int type);
char	*fill_token_lexer(char *str, int *i, int type);
char	*fill_token_lexer_normed(char *str, int *i, int type, char *ret);
int		get_len_token_lexer(char *str, int i, int type);
int		get_len_token_lexer_normed(char *str, int i, int type, int len);
int		check_token_normed(char c, char d);
int		check_token(char c, char d);
void	print_lexer(t_lexer	*lexer);
t_lst	*get_parsed(t_lexer	*lexer, t_data *data);
char	*fill_quote(t_lexer **lexer, t_data *data, char *res);
char	*fill_dollar(t_lexer **lexer, t_data *data, char *res);
char	*fill_simple_quote(t_lexer **lexer, char *res);
void	fill_rout(t_lexer **lexer, t_data *data);
void	fill_rin(t_lexer **lexer, t_data *data);
char	*fill_export(t_lexer **lexer, t_data *data, char *res);
int		ft_strcmp(char *s1, char *s2);

#endif