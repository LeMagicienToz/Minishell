/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:16 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/05 15:42:23 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
				if (check_token(str[i++], (char) NULL) == TEXT)
					return (1);
			}
			data->status = 258;
			return (2);
		}
		i++;
	}
	return (0);
}

char	*fill_end(char *str, int len, int i)
{
	char	*end;
	int		x;

	end = malloc(sizeof(char) * (len + 1));
	end[len] = '\0';
	x = 0;
	while (str[i] && !ft_is_space(str[i]))
		end[x++] = str[i++];
	return (end);
}

char	*fill_here_doc(char *str)
{
	int		i;
	int		x;
	int		len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<' && str[i + 1] == '<')
		{
			i = i + 2;
			while (ft_is_space(str[i]))
				i++;
			x = i;
			while (str[i] && !ft_is_space(str[i++]))
				len++;
			i = x;
			break ;
		}
		i++;
	}
	return (fill_end(str, len, i));
}

char	*here_doc_normed(char *res, char *tmp, char *read, char *end)
{
	while (1)
	{
		if (read)
			free(read);
		read = readline("> ");
		if (!ft_strcmp(read, end))
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
