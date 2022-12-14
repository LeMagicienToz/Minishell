/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:26:29 by rperrin           #+#    #+#             */
/*   Updated: 2022/12/14 00:29:15 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	lol(int j, int v)
{
	int 	fd;
	char	c;
	int		i;
	int		x;

	fd = open("lol.txt", O_RDONLY);
	i = 30;
	x = 0;
	while (x != j)
	{
		while (i < 48)
		{
			printf("\033[5;%d;0m\n", i++);
			while (read(fd, &c, 1) > 0)
				printf("%c", c);
			printf("\033[0m\n");
			i++;
			close(fd);
			fd = open("lol.txt", O_RDONLY);
		}
		i = 30;
		usleep(v);
		x++;
	}
}
