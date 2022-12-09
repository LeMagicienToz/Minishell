/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:32 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/09 02:42:40 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
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
}	t_utils;

typedef struct s_data
{
	char	*input;
	char	*cmd;
	char	*settings;
	char	*args;
	t_utils	*u;
}	t_data;

void	check_command(char **str, char **envp);
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
int		ft_getlen_remove_quote(char *str);
char	*ft_remove_quote(t_utils *u, char *str);
char	*ft_check_quote(char *res, char *str, int i, int code);
#endif