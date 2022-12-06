/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:32:12 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/06 15:55:34 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_get_code(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == DBQUOTECODE)
			return (DBQUOTECODE);
		else if (str[i] == QUOTECODE)
			return (QUOTECODE);
		i++;
	}
	return (0);
}

int	ft_len_quote(char *str, int code)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == code)
			len++;
		i++;
	}
	return (len);
}

char	*ft_remove_quote(char *str)
{
	char	*res;
	int		i;
	int		j;
	int		code;

	code = ft_get_code(str);
	if (code == 0)
		return (str);
	j = 0;
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) - ft_len_quote(str, code)) + 1);
	while (str[i])
	{
		if (str[i] == code)
			i++;
		printf("res %p [%c]\n", &res[i], str[i]);
		if (str[i])
			res[j] = str[i];
		else
			break ;
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

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

char	*ft_remove_cmd(char *input, int lencmd)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(input) - lencmd));
	i = lencmd + 1;
	j = 0;
	while (input[i])
		tmp[j++] = input[i++];
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_get_arg(char *input, int lencmd)
{
	char	*res;
	char	*tmp;

	tmp = ft_remove_cmd(input, lencmd);
	res = ft_remove_space(tmp);
	free (tmp);
	tmp = ft_remove_quote(res);
	free(res);
	return (tmp);
}
