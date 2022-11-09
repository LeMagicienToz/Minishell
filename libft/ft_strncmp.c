/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:40:32 by rperrin           #+#    #+#             */
/*   Updated: 2021/11/03 15:31:30 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	ss1;
	unsigned char	ss2;

	i = 0;
	if (!n)
		return (n);
	ss1 = (unsigned char)s1[i];
	ss2 = (unsigned char)s2[i];
	while ((ss1 && ss2) && (i < n))
	{
		ss1 = (unsigned char)s1[i];
		ss2 = (unsigned char)s2[i];
		if (ss1 != ss2)
			return (ss1 - ss2);
		i++;
	}
	return (ss1 - ss2);
}
