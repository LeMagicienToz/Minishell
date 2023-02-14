/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:16 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/14 21:40:50 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signal_handler_heredoc(int signo)
{
	if (signo == SIGINT)
	{
		g_errors.heredoc_signal = 1;
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
		signal(SIGINT, signal_handler_heredoc);
		signal(SIGQUIT, SIG_IGN);
		if (read)
			free(read);
		read = readline("> ");
		if (!ft_strcmp(read, end) || !read)
			break ;
		if (!res)
			res = ft_strdup(read);
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

	res = NULL;
	read = NULL;
	tmp = NULL;
	data->in = open("heredoc", O_RDWR | O_CREAT, S_IRUSR + \
				S_IWUSR + S_IRGRP + S_IROTH);
	res = here_doc_normed(res, tmp, read, end);
	write (data->in, res, ft_strlen(res));
}
