/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:25:05 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/14 15:39:07 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	get_cmd(char *str)
{
	char **args;

	if (!ft_strncmp(str, "history", ft_strlen(str)))
	{
		cmd_history();	
		return (-1);
	}
	else if (!ft_strncmp(str, "debug leaks", ft_strlen(str))) //Pour voir les leaks de notre minishello
	{
		system("leaks Minishell | grep leaks | tail -1");
		return (-1);
	}
	else if (str[0] == 'l' && str[1] == 'o' && str[2] == 'l')
	{
		args = ft_split(str, ' ');
		lol(ft_atoi(args[1]), ft_atoi(args[2]));
		return (-1);
	}
	else if (!ft_strncmp(str, "exit", ft_strlen(str)))
		return (-2);
	else
		return (1);
}

void	cmd_history(void)
{
	HISTORY_STATE	*myhist;
	HIST_ENTRY		*mylist;
	int				i;

	i = 0;
	myhist = history_get_history_state();
	while (i < myhist->length)
	{
		mylist = history_get(i + 1);
		ft_putstr_fd("    ", 1);
		ft_putnbr_fd(i++ + 1, 1);
		ft_putstr_fd("  ", 1);
		ft_putstr_fd((char *)mylist[0].line, 1);
		ft_putchar_fd('\n', 1);
	}
	free(myhist);
}
