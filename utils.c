/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:20:02 by raphaelperr       #+#    #+#             */
/*   Updated: 2022/12/03 14:12:53 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

//utile pour ft_stripwhite
int	ft_strlen_white(char *str)
{
	int	white;
	int	i;

	i = 0;
	white = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			white++;
		else
			break ;
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == ' ')
			white++;
		else
			break ;
		i--;
	}
	if (ft_strlen(str) - white == 0)
		return (1);
	return (ft_strlen(str) - white);
}

// pour pas segfault quand il n'y a pas de lettre
int	ft_check_word(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			j++;
		i++;
	}
	return (j);
}

//ft_stripwhite enlève les espaces avant et après une commande
char	*ft_stripwhite(char *str)
{
	int		i;
	int		j;
	int		x;
	char	*result;
	int		len;

	x = 0;
	i = 0;
	j = 0;
	len = ft_strlen_white(str);
	result = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		while (str[j] == ' ' && x == 0)
			j++;
		x = 1;
		result[i++] = str[j++];
	}
	result[i] = '\0';
	free(str);
	return (result);
}

void	ft_putnbr_base(int nb, int digit, char *base, int fd)
{
	if (nb < 0 && digit == 10)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base(-nb, digit, base, fd);
	}
	if (nb > 9)
	{
		ft_putnbr_base(nb / digit, digit, base, fd);
		ft_putchar_fd(base[nb % digit], fd);
	}
	else
		ft_putchar_fd(base[nb % digit], fd);
}

void	ft_printf_fd(int fd, char *str, ...)
{
	va_list	lst;
	int		i;

	va_start(lst, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || \
		str[i + 1] == 'x' || str[i + 1] == 's' || str[i + 1] == 'c'))
		{
			i++;
			if (str[i] == 'd')
				ft_putnbr_base(va_arg(lst, int), 10, "0123456789", fd);
			if (str[i] == 'x')
				ft_putnbr_base(va_arg(lst, int), 16, "0123456789abcdef", fd);
			if (str[i] == 's')
				ft_putstr_fd(va_arg(lst, char *), fd);
			if (str[i] == 'c')
				ft_putchar_fd(va_arg(lst, int), fd);
			i++;
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(lst);
}
