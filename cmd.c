/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:25:05 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/11/16 11:17:47 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

int	get_cmd(char *str)
{
	if (!ft_strncmp(str, "history", ft_strlen(str)))
		cmd_history();
	if (!ft_strncmp(str, "exit", ft_strlen(str)))
		return (1);
	else
		return (0);
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
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(i++ + 1, 1);
		ft_putstr_fd("  ", 1);
		ft_putstr_fd((char *)mylist[0].line, 1);
		ft_putchar_fd('\n', 1);
	}
	free(myhist);
}
