/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:30 by muteza            #+#    #+#             */
/*   Updated: 2023/02/08 04:53:14 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	replace_export(t_data *data, int x, char *add)
{
	t_lst 	**lst;
	t_lst 	*tmp;
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

int	check_exicting(t_data *data, char *str)
{
	int		i;
	t_lst	*tmp;
	char	*check;
	char	*noleaks;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	printf("i %d == %d\n\n", i, (int)ft_strlen(str));
	if (i == (int)ft_strlen(str))
	{
		noleaks = ft_strdup(str);
		check = ft_strjoin(noleaks, "=");
		free(noleaks);
	}
	else
		check = ft_substr(str, 0, i + 1);
	printf("check[%s]\n", check);
	tmp = data->export;
	i = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, check) == 0)
			return (i);
		i++;
		tmp = tmp->next;
	}
	free(check);
	return (-1);
}

int	parcing_export(t_data *data)
{
	int	i;

	i = 0;
	if (ft_isdigit(data->str[1][0]))
		return (0);
	while (data->str[1][i] && data->str[1][i] != '=')
	{
		if ((ft_isalpha(data->str[1][i]) || ft_isdigit(data->str[1][i])))
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

	i = 0;
	if (!parcing_export(data))
		perror("AAAALLLLEEERTTTE\n");
	x = check_exicting(data, data->str[1]);
	printf("x==%d\n", x);
	if (parcing_export(data) == 2 && x == -1)
		add_with_no_egual(data);
	else if (x == -1)
	{
		i = 0;
		while (data->str[1][i] != '=')
			i++;
		i++;
		str = ft_substr(data->str[1], 0, i);
		create_token(data, &data->export, str, 0);
		free(str);
		str = ft_substr(data->str[1], i, (ft_strlen(data->str[1]) - i));
		create_token(data, &data->export, str, 0);
		free(str);
	}
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

int	check_equal(t_data *data)
{
	int		k;
	int		i;
	t_lst	*tmp;

	tmp = data->export;
	i = 0;
	k = 0;
	while (data->str[1][i])
	{
		if (data->str[1][i] == '=')
			k = 1;
		i++;
	}
	if (k == 1)
	{
		add_to_export(data);
	}
	else
		add_to_export(data);
	return (i);
}
