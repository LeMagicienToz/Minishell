/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:30 by muteza            #+#    #+#             */
/*   Updated: 2023/01/26 09:24:07 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	replace_in_two(t_data *data, char *str, char *rep)
{
	int		i;
	t_lst	*tmp;
	(void)rep;

	tmp = data->export;
	i = 0;
	while (ft_strcmp(str, data->export->content) != 0)
		data->export = data->export->next;
	// while (da)
	
	// printf("%s\n\n\n", data->export->content);
	// data->export->content = ft_strcpy(data->export->content, rep);
	// printf("%s\n\n\n", data->export->content);
}

void	add_to_export(t_data *data)
{
	int		i;
	int		k;
	t_lst	*tmp;
	char	*dec;

	k = 0;
	i = 0;
	dec = "declare -x ";
	tmp = data->export;
	dec = ft_strjoin(dec, data->str[1]);
	while (tmp)
	{
		while (tmp->content[i] != '=' && dec[i] != '=')
		{
			// printf("%s\n", tmp->content);
			if (tmp->content[i] == dec[i])
			{
				i++;
			}
			else
				break ;
		}
		if (tmp->content[i] == dec[i])
		{
			// printf("%c\n", tmp->content[i]);
			replace_in_two(data, tmp->content, dec);
			break ;
		}
		tmp = tmp->next;
	}
}

void	add_to_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp[i])
		i++;
	data->envp[i] = malloc(sizeof(char) * ft_strlen(data->str[1]) + 1);
	data->envp[i] = ft_strcpy(data->envp[i], data->str[1]);
	i++;
	data->envp[i] = NULL;
	i = 0;
}

int	check_equal(t_data *data)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (data->str[1][k])
	{
		if (data->str[1][k] == '=')
		{
			i = 1;
			add_to_env(data);
			add_to_export(data);
		}
		k++;
	}
	return (i);
}
