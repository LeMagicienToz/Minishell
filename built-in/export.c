/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:44:53 by muteza            #+#    #+#             */
/*   Updated: 2023/01/19 18:23:46 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_sort(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data->envp[i])
		i++;
	while (data->exp[k])
		k++;
	if (k < i)
		return (0);
	else
		return (1);
}

int	sorting(t_data *data)
{
	int		i;
	int		k;
	int		j;
	char	*tmp;

	k = 0;
	j = 0;
	i = 0;
	while (data->envp[i])
		i++;
	data->exp = malloc((sizeof(char *)) * i);
	i = 0;
	while (data->envp[i])
	{
		data->exp[i] = malloc(sizeof(char) * ft_strlen(data->envp[i]));
		data->exp[i] = ft_strcpy(data->exp[i], data->envp[i]);
		i++;
	}
	printf("%d\n",i);
	while (k < i)
	{
		while (j < (i - k - 1))
		{
			if (ft_strcmp(data->exp[j], data->exp[j + 1]) > 0)
			{
				tmp = data->exp[j];
				data->exp[j] = data->exp[j + 1];
				data->exp[j + 1] = tmp;
			}
			j++;
		}
		k++;
	}
	return (0);
}

int	triable(t_data *data)
{
	int	v;

	v = 0;
	printf("%d\n", ft_strcmp("coat","daog"));
	sorting(data);
	// while (data->exp[v])
	// {
	// 	printf("%s\n", data->exp[v]);
	// 	v++;
	// }
	return (0);
}

void	ft_export(t_data *data)
{
	triable(data);
}
