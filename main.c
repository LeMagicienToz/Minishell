/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:22:44 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/09 17:40:00 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	return (ft_strlen(str) - white);
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
	return (result);
}

int	main(void)
{
	char	*command_buffer;

	while (1)
	{
		command_buffer = readline("Minishello 🤌 >");
		if (ft_strlen(command_buffer) > 0)
		{
			command_buffer = ft_stripwhite(command_buffer);
			add_history(command_buffer);
			printf("%s\n", command_buffer);
		}
		else
			ft_putendl_fd("NO ENTER", 1);
		free(command_buffer);
	}
	return (0);
}
