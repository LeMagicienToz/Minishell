/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:29:24 by raphaelperr       #+#    #+#             */
/*   Updated: 2023/02/08 21:13:37 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_echo_pipe(t_data *data, t_lst *lst)
{
	if (data->str[1])
	{
		if (lst->n == 1)
			write(data->fd[1], data->str[1], ft_strlen(data->str[1]));
		else
		{
			write(data->fd[1], data->str[1], ft_strlen(data->str[1]));
			write(data->fd[1], "\n", 1);
		}
	}
	else if (lst->n != 1)
		write(data->fd[1], "\n", 1);
}

void	ft_echo(t_data *data, t_lst *lst)
{
	if (data->str[1] && lst->next)
		print_echo_pipe(data, lst);
	else if (data->str[1])
	{
		if (lst->n == 1)
			printf("%s", data->str[1]);
		else
			printf("%s\n", data->str[1]);
	}
	else if (lst->n != 1)
		printf("\n");
}
