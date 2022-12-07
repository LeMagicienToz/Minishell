/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:32:12 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/07 00:04:06 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_get_code(char *str, int i)
{
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

t_data	*ft_len_quote(t_data *data, char *str, int code)
{
	while (str[data->i] == code)
		data->i++;
	while (str[data->i])
	{
		if (str[data->i] == code)
		{
			while (str[data->i] != code)
			{
				data->len++;
				data->i++;
			}
			dprintf(2, "[DEBUG] i(%d) len(%d)\n", data->i, data->len);
			break ;
		}
		data->i++;
	}
	return (data);
}

int	ft_len_remove_quote2(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == DBQUOTECODE)
		{
			i++;
			while (str[i++] != DBQUOTECODE)
			{
				len++;
				i++;
			}	
		}
		else if (str[i] == QUOTECODE)
		{
			i++;
			while (str[i++] != QUOTECODE)
			{
				len++;
				i++;
			}	
		}
		i++;

	}
	return (len);
}

char	*ft_remove_quote2(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ft_len_remove_quote2(str) + 1);
	while (str[i])
	{
		if (str[i] == DBQUOTECODE)
		{
			i++;
			while (str[i] != DBQUOTECODE)
				res[j++] = str[i++];
		}
		else if (str[i] == QUOTECODE)
		{
			while (str[i] != QUOTECODE)
				res[j++] = str[i++];	
		}
		res[j++] = str[i++];
	}
	res[j] = '\0';
	return (res);
}

char	*ft_remove_quote(t_data *data, char *str)
{
	char	*res;
	int		i;
	int		j;
	int		code;

	j = 0;
	i = 0;
	code = ft_get_code(str, i);
	if (code == 0)
		return (str);
	data = ft_len_quote(data, str, code);
	res = malloc(sizeof(char) * (ft_strlen(str) - data->len) + 1);
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
	tmp = ft_remove_quote2(res);
	free(res);
	return (tmp);
}
