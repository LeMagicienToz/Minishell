/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:05:32 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/04 19:54:42 by raphaelperr      ###   ########.fr       */
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

typedef struct s_data
{
	char	**input;
	char	*cmd;
	char	*settings;
	char	**args;
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
char	**ft_get_arg(char *str);
char	*ft_split_arg(char *str, char c);
int		ft_strlen_split(char *str, char c);
#endif