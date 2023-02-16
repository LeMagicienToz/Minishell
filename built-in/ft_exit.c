/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:19:43 by muteza            #+#    #+#             */
/*   Updated: 2023/02/16 18:40:54 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(t_data *data)
{
	if (data->str[1] && data->maxindex == 0)
	{
		if (ft_is_numeric(data->str[1]) == 0)
			data->status = ft_atoi(data->str[1]);
		else
			printf("ERROR\n");
	}
	if (data->maxindex == 0)
		exit(0);
}
