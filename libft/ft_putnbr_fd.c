/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:34:32 by rperrin           #+#    #+#             */
/*   Updated: 2022/11/04 17:01:18 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(unsigned int nb, int fd)
{
	// else if (nb < 0)
	// {
	// 	ft_putchar_fd('-', fd);
	// 	ft_putnbr_fd(-nb, fd);
	// }
	if (nb < 10)
	{
		ft_putchar_fd(nb + 48, fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}
