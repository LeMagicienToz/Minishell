/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:16 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/15 14:53:49 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signal_handler_heredoc(int signo)
{
	if (signo == SIGINT)
	{
		// g_errors.heredoc_signal = 1;
		// exit(0);
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
		printf("[%c]\n", signo);
}

int	check_here_doc(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == INCODE && str[i + 1] == INCODE)
		{
			i = i + 2;
			while (str[i] && str[i] != PIPECODE)
			{
				if (check_token(str[i++], (char)0) == TEXT)
					return (1);
			}
			data->status = 403;
			return (2);
		}
		i++;
	}
	return (0);
}

char	*here_doc_normed(char *res, char *tmp, char *read, char *end)
{
	while (1)
	{
		if (read)
			free(read);
		read = readline("> ");
		if (!read)
		{
			printf("CTRL +D\n");
			break;
		}
		if (!ft_strcmp(read, end) || !read)
			break ;
		if (!res)
		{
			res = ft_strdup(read);
		}
		else
		{
			tmp = ft_strdup(res);
			free(res);
			res = ft_strjoin(tmp, read);
			free(tmp);
		}
	}
	return (res);
}

void	here_doc(char *end, t_data *data)
{
	char	*res;
	char	*tmp;
	char	*read;
	int		vv;
	int		id;

	res = NULL;
	read = NULL;
	tmp = NULL;
	data->in = open("heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0600);
	signal(SIGINT, signal_handler_heredoc);
	signal(SIGQUIT, SIG_IGN);
	id = fork();
	if (id == 0)
	{
		res = here_doc_normed(res, tmp, read, end);
		// data->heredocres = ft_strdup(res);
		printf("(%s)\n", res);
		waitpid(id, &vv, 0);
		if (res)
			write (data->in, res, ft_strlen(res));
		exit (1);
	}
}
