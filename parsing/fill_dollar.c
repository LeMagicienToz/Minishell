/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:32:42 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/22 02:14:06 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_dollar_token(char *str, t_data *data)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	data->dollartoken = NULL;
	while (str[i])
	{
		if (!ft_isalnum(str[i++]))
		{
			res = ft_substr(str, 0, i - 1);
			data->dollartoken = ft_substr(str, i - 1, ft_strlen(str));
		}
	}
	if (!res)
		res = ft_strdup(str);
	return (res);
}

char	*fill_dollar_normdeouf(t_data *data, char *leaks, char *res)
{
	leaks = ft_strdup(res);
	free(res);
	res = ft_strjoin(leaks, data->dollartoken);
	free(data->dollartoken);
	free(leaks);
	return (res);
}
