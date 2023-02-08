/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_env_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 03:05:41 by muteza            #+#    #+#             */
/*   Updated: 2023/02/08 04:06:39 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_with_no_egual(t_data *data)
{
	char	*tmp;

	data->typeout = 1;
	tmp = ft_strdup(data->str[1]);
	free(data->str[1]);
	data->str[1] = ft_strjoin(tmp, "=");
	free(tmp);
	create_token(data, &data->export, data->str[1], 0);
	free(data->str[1]);
	create_token(data, &data->export, ft_strdup("\0"), 0);
	print_lst(data->export);
}