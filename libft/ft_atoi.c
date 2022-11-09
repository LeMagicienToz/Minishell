/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:34:11 by rperrin           #+#    #+#             */
/*   Updated: 2021/10/25 12:36:14 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_neg(const char *str)
{
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	while (str[i] && !ft_isdigit(str[i]))
	{
		if (str[i] == '-')
			neg = -1;
		else if (str[i] == '+')
			neg = 1;
		i++;
	}
	return (neg);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	int_max_or_min(const char *str)
{
	if (ft_strcmp(str, "-2147483648") == 0)
		return (INT_MIN);
	else if (ft_strcmp(str, "2147483647") == 0)
		return (INT_MAX);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		n;
	int		i;
	int		neg;

	n = 0;
	i = 0;
	if ((ft_strcmp(str, "-2147483648") == 0))
		return (int_max_or_min(str));
	else if ((ft_strcmp(str, "2147483647") == 0))
		return (int_max_or_min(str));
	neg = (ft_neg(str));
	while (str[i] && ((str[i] > 8 && str[i] < 14) || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit((int)str[i]))
	{
		n *= 10;
		n += (str[i] - '0');
		i++;
	}
	return (n * neg);
}
