/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:13:30 by muteza            #+#    #+#             */
/*   Updated: 2023/01/26 15:42:44 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_export_to_export(t_data *data, char *dec)
{
	t_lst	*tmp;
	char	*str;
	int		i = 0;
	int		k = 0;

	str = malloc(sizeof(char) * (ft_strlen(dec) + 2));
	while (dec[i] != '=')
	{
		str[i] = dec[i];
		i++;
	}
	str[i] = dec[i];
	i++;
	k = i;
	str[i] = '"';
	i++;
	while (dec[k])
	{
		str[i] = dec[k];
		k++;
		i++;
	}
	str[i] = '"';
	tmp = create_node(data, str);
	addback(tmp, &data->export);
	free(str);
}

void	replace_in_two(t_data *data, char *dec)
{
	t_lst	*tmp;
	t_lst	**tmp1;
	char	*str;
	int		i = 0;
	int		k = 0;

	tmp1 = &data->export;
	tmp = (*tmp1);
	str = malloc(sizeof(char) * (ft_strlen(dec) + 2));
	while (dec[i] != '=')
	{
		str[i] = dec[i];
		i++;
	}
	str[i] = dec[i];
	i++;
	k = i;
	str[i] = '"';
	i++;
	while (dec[k])
	{
		str[i] = dec[k];
		k++;
		i++;
	}
	str[i] = '"';
	// printf("\n\n\n\n\n%s\n\n\n\n", str);
	while (data->ex_ind - 1 != 0)
	{
		tmp = tmp->next;
		data->ex_ind--;
	}
	// printf("test %s\n", tmp->content);
	free(tmp->content);
	tmp->content = ft_strdup(str);
	// tmp->content = ft_strcpy(tmp->content, str);
	// tmp = create_node(data, str);
	// addback(tmp, &data->export);
	free(str);
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
	data->ex_ind = 0;
	dec = ft_strjoin(dec, data->str[1]);
	while (tmp)
	{
		data->ex_ind++;
		while (tmp->content[i] != '=' && dec[i] != '=' )
		{
			if (tmp->content[i] == dec[i])
			{
				i++;
			}
			else
				break ;
		}
		if (tmp->content[i] == dec[i])
		{
			k = 1;
			replace_in_two(data, dec);
			free(dec);
			break ;
		}
		tmp = tmp->next;
	}
	if (k == 0)
	{
		add_export_to_export(data, dec);
		free(dec);
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
			// print_lst(data->export);
		}
		k++;
	}
	return (i);
}
