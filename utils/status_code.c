/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:57:27 by rperrin           #+#    #+#             */
/*   Updated: 2023/02/08 16:55:13 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	status_init(t_data *data)
// {
// 	char	*line;
// 	int		fd;
// 	int		i;

// 	fd = open("statuscode", O_RDONLY);
// 	data->errors = malloc(sizeof(char *) * (130 + 1));
// 	data->errors[0] = ft_strdup("Success");
// 	i = 1;
// 	while (i <= 129)
// 	{
// 		// line = get_next_line(fd);
// 		data->errors[i] = ft_strdup(line);
// 		printf("%d:%s\n", i, data->errors[i]);
// 		free(line);
// 		i++;
// 	}
// 	data->errors[130] = NULL;
// }
