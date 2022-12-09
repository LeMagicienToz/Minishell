/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:47:02 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/08 22:47:56 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_len_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] == ' ' && str[j + 1] == ' ')
		{
			j++;
			i++;
		}
		j++;
	}
	return (j - i);
}

char	*ft_remove_space(char *str)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = malloc(sizeof(char) * ft_len_space(str) + 1);
	while (str[i])
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		res[j++] = str[i++];
	}
	res[j] = '\0';
	return (res);
}
