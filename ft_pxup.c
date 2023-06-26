/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pxup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:03:57 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/11 22:08:17 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_pxup(unsigned int nbr, int fd)
{	
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_pxup(nbr / 16, fd);
		count += ft_pxup(nbr % 16, fd);
	}
	else
	{
		if (nbr < 10)
			count += ft_putchar_fd(nbr + 48, fd);
		else
			count = count + ft_putchar_fd("0123456789ABCDEF" [nbr], fd);
	}
	return (count);
}
