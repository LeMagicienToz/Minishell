/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:16:40 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/05 17:26:56 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_data(t_data *data, char **envp)
{
	data->envp = envp;
	data->maxindex = 0;
	data->status = 0;
	data->out = 0;
	data->in = 0;
	data->typeout = 0;
	data->checkexport = 0;
	data->errorlexer = NULL;
}

void	init_exp(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	data->export = NULL;
	j = 0;
	i = 0;
	while (data->tomp[i])
	{
		if (data->tomp[i][j++] == EQUALCODE)
		{
			tmp = ft_substr(data->tomp[i], 0, j);
			create_token(data, &data->export, tmp, 0);
			free(tmp);
			tmp = ft_substr(data->tomp[i], j, (ft_strlen(data->tomp[i]) - j));
			create_token(data, &data->export, tmp, 0);
			free(tmp);
			i++;
			j = 0;
		}
	}
}

void	init_lst(t_lst	**lst)
{
	t_lst	*tmp;

	printf("%s:%d\n", __FILE__, __LINE__);
	tmp = (*lst);
	tmp = NULL;
}

void	init_lex(t_lexer	**lex)
{
	t_lexer	*tmp;

	printf("%s:%d\n", __FILE__, __LINE__);
	tmp = (*lex);
	tmp = NULL;
}
