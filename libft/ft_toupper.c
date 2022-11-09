/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 23:09:45 by rperrin           #+#    #+#             */
/*   Updated: 2022/09/07 00:36:13 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_ismin(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_toupper(int c)
{
	if (ft_ismin(c))
		return (c - 32);
	else
		return (c);
}
