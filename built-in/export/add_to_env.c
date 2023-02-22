/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:30 by muteza            #+#    #+#             */
/*   Updated: 2023/02/22 02:50:39 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_exicting_env(t_data *data, char *str)
{
	int		i;
	t_lst	*tmp;
	char	*check;
	char	*noleaks;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (i == (int)ft_strlen(str))
	{
		noleaks = ft_strdup(str);
		check = ft_strjoin(noleaks, "=");
		free(noleaks);
	}
	else
		check = ft_substr(str, 0, i + 1);
	tmp = data->env;
	i = check_ex_env(tmp, check);
	free(check);
	return (i);
}

void	replace_export(t_data *data, int x, char *add)
{
	t_lst	**lst;
	t_lst	*tmp;
	int		i;

	i = 0;
	lst = &data->export;
	tmp = (*lst);
	while (tmp)
	{
		if (i == x)
		{
			if (tmp->typeout == 1)
				tmp->typeout = 0;
			tmp = tmp->next;
			if (tmp->typeout == 1)
				tmp->typeout = 0;
			free(tmp->content);
			tmp->content = ft_strdup(add);
		}
		i++;
		tmp = tmp->next;
	}
}

int	check_exicting_exp(t_data *data, char *str)
{
	int		i;
	t_lst	*tmp;
	char	*check;
	char	*noleaks;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (i == (int)ft_strlen(str))
	{
		noleaks = ft_strdup(str);
		check = ft_strjoin(noleaks, "=");
		free(noleaks);
	}
	else
		check = ft_substr(str, 0, i + 1);
	tmp = data->export;
	i = check_ex_exp(tmp, check);
	free(check);
	return (i);
}

int	parcing_export(t_data *data)
{
	int	i;

	i = 0;
	if (ft_isdigit(data->str[1][0]))
		return (0);
	while (data->str[1][i] && data->str[1][i] != '=')
	{
		if ((ft_isalpha(data->str[1][i]) || ft_isdigit(data->str[1][i]) || \
		data->str[1][i] == '_'))
			i++;
		else
			return (0);
	}
	if (i == (int)ft_strlen(data->str[1]))
		return (2);
	return (1);
}

int	add_to_export(t_data *data)
{
	char	*str;
	int		i;
	int		x;

	str = NULL;
	i = 0;
	if (!parcing_export(data))
		erreur_status(1, "Parcing export goes wrong\n", data, 0);
	x = check_exicting_exp(data, data->str[1]);
	if (parcing_export(data) == 2 && x == -1)
		add_with_no_egual(data);
	else if (x == -1)
		normed_add_to_export(i, data, str);
	else if (x == -2)
		return (0);
	else if (parcing_export(data) != 2)
	{
		while (data->str[1][i] && data->str[1][i] != '=')
			i++;
		str = ft_substr(data->str[1], i + 1, (ft_strlen(data->str[1]) - i));
		replace_export(data, x, str);
		free(str);
	}
	return (0);
}
