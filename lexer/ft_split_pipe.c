/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:38:33 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/06 21:41:11 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 00:42:35 by rperrin           #+#    #+#             */
/*   Updated: 2021/10/22 01:31:27 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	split_de_split_pipe(int *i, char const *s, char c, t_data *data)
{
	int	j;
	int	x;

	x = 0;
	while (s[*i] && s[*i] == c)
	{
		if (s[(*i)++] == PIPE)
			x++;
		if (x > 1)
			data->errorlexer = "syntax error near unexpected token `|'";
	}
	j = 0;
	while (s[*i + j] && s[*i + j] != c)
		j++;
	return (j);
}

static char	**split_error_pipe(char **res, int n)
{
	while (n--)
		free(res[n]);
	free(res);
	return (NULL);
}

static char	**malloc_res_pipe(char const *s, char c)
{
	int		nb_word;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	nb_word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb_word++;
		while (s[i] && s[i] != c)
			i++;
	}
	res = malloc(sizeof(char *) * (nb_word + 1));
	if (!res)
		return (NULL);
	res[nb_word] = NULL;
	return (res);
}

char	**ft_split_pipe(const char *s, char c, t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = malloc_res_pipe(s, c);
	if (!res)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		j = split_de_split_pipe(&i, s, c, data);
		if (j > 0)
		{
			res[k++] = ft_substr(s, i, j);
			if (!res[k - 1])
				return (split_error_pipe(res, k - 1));
		}
		i = i + j;
	}
	return (res);
}
