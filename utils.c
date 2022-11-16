/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:20:02 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/15 20:10:48 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

//utile pour ft_stripwhite
int	ft_strlen_white(char *str)
{
	int	white;
	int	i;

	i = 0;
	white = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			white++;
		else
			break ;
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == ' ')
			white++;
		else
			break ;
		i--;
	}
	if (ft_strlen(str) - white == 0)
		return (1);
	return (ft_strlen(str) - white);
}

// pour pas segfault quand il n'y a pas de lettre
int	ft_check_word(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			j++;
		i++;
	}
	return (j);
}

//ft_stripwhite enlève les espaces avant et après une commande
char	*ft_stripwhite(char *str)
{
	int		i;
	int		j;
	int		x;
	char	*result;
	int		len;

	x = 0;
	i = 0;
	j = 0;
	len = ft_strlen_white(str);
	result = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		while (str[j] == ' ' && x == 0)
			j++;
		x = 1;
		result[i++] = str[j++];
	}
	result[i] = '\0';
	free(str);
	return (result);
}
