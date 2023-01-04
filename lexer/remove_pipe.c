/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:42:26 by rperrin           #+#    #+#             */
/*   Updated: 2023/01/04 18:50:41 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	remove_pipe(t_lst **lst)
// {
// 	t_lst *tmp;

// 	t_lst* current = *lst;
//     t_lst* next = NULL;
// 	tmp = (*lst);
// 	while (tmp)
// 	{
// 		printf("%s\n", tmp->content);
// 		if (ft_strchr(tmp->content, '|'))
// 			free(tmp);
// 		tmp = tmp->next;
// 	}
// }