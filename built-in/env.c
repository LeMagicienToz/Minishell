/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:17:12 by muteza            #+#    #+#             */
/*   Updated: 2023/02/08 19:57:36 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	add_to_env(t_data *data)
{
	(void)data;
}

void	ft_env(t_data *data, t_lst *lst)
{
	int	i;
	(void)lst;

	i = 0;
	// if (lst->next)
	// {
	// }
	while (data->envp[i])
	{
		printf("%s\n", data->envp[i]);
		i++;
	}
}
