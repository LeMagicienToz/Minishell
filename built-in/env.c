/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:17:12 by muteza            #+#    #+#             */
/*   Updated: 2023/02/20 16:40:35 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	replace_env(t_data *data, int x, char *add)
{
	t_lst	**lst;
	t_lst	*tmp;
	int		i;

	i = 0;
	lst = &data->env;
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

void	add_to_env(t_data *data)
{
	int		x;
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	x = check_exicting_env(data, data->str[1]);
	if (x == -1)
		normed_add_to_env(data, str);
	else if (parcing_export(data) != 2)
	{
		while (data->str[1][i] && data->str[1][i] != '=')
			i++;
		str = ft_substr(data->str[1], i + 1, (ft_strlen(data->str[1]) - i));
		replace_env(data, x, str);
		free(str);
	}
}

void	print_env(t_data *data, t_lst *tmp)
{
	int	i;

	(void)data;
	i = 0;
	while (tmp)
	{
		if (i % 2 == 0)
		{
			if (tmp->typeout == 0)
				printf("%s", tmp->content);
			else
			{
				write(1, tmp->content, ft_strlen(tmp->content) - 1);
			}
		}
		else if (tmp->typeout == 0)
			printf("%s\n", tmp->content);
		else
			printf("\n");
		i++;
		tmp = tmp->next;
	}
}

void	print_env_in_pipe(t_data *data, t_lst *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (i % 2 == 0)
			write(data->fd[1], tmp->content, ft_strlen(tmp->content));
		else if (tmp->typeout == 0)
		{
			write(data->fd[1], tmp->content, ft_strlen(tmp->content));
			write(data->fd[1], "\n", 1);
		}
		else
			write(data->fd[1], "\n", 1);
		i++;
		tmp = tmp->next;
	}
}

void	ft_env(t_data *data, t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	tmp = data->env;
	i = 0;
	if (!data->str[1])
	{
		if (lst->next)
			print_env_in_pipe(data, tmp);
		else
			print_env(data, tmp);
	}
	else if (check_equal_env(data))
	{
		print_env(data, tmp);
		printf("%s\n", data->str[1]);
	}
	else
		erreur_status(127, "Error: env: No such file or directory", data, 0);
}
