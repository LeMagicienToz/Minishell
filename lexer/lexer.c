/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:13:27 by rperrin           #+#    #+#             */
/*   Updated: 2022/12/21 23:14:14 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		check_separator(char c)
{
	if (c == DBQUOTECODE)
		return (DBQUOTECODE);
	else if (c == QUOTECODE)
		return (QUOTECODE);
	else if (c == HYPHENCODE)
		return (HYPHENCODE);
	else if (c == SPACECODE)
		return (SPACECODE);
	else
		return (-1);
}

t_lst	*create_node(char *str)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	node->content = ft_strdup(str);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	addback(t_lst *node, t_lst **lst)
{
	t_lst	*tmp;

	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void	create_token(t_lst **lst, char *str)
{
	t_lst	*node;
	int		i;

	i = 0;
	if ((*lst) == NULL)
		(*lst) = create_node(str);
	else
	{
		node = create_node(str);
		addback(node, lst);	
	}
}

// int	main(void)
// {
// 	t_lst *lst;
// 	t_lst *tmp;
// 	lst = NULL;
// 	create_token(&lst, "test test2");
// 	tmp = lst;
// 	while (tmp)
// 	{
// 		printf("%s\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }

int	get_len_token(char *str, int i, int last)
{
	int	len;

	len = 0;
	if (last < 0)
	{
		while (check_separator(str[i]) < 0 && str[i++])
			len++;
		return (len);
	}
	while (check_separator(str[i]) != last && str[i++])
		len++;
	return (len);
}

t_lst	*detect_token(t_lst *lst, char *str)
{
	int		i;
	int		j;
	int		len;
	int		last;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((last = check_separator(str[i])) > 0)
		{
			i++;
			len = get_len_token(str, i, last);
			tmp = malloc(sizeof(char) * len + 1);
			while (check_separator(str[i]) != last && str[i])
				tmp[j++] = str[i++];
			if (str[i] == last)
				i++;
		}
		else
		{
			len = get_len_token(str, i, last);
			tmp = malloc(sizeof(char) * len + 1);
			while (check_separator(str[i]) < 0 && str[i])
				tmp[j++] = str[i++];
		}
		tmp[j] = '\0';
		create_token(&lst, tmp);
		free(tmp);
		j = 0;
	}
	return lst;
}
