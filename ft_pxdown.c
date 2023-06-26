/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:30:53 by gbarone           #+#    #+#             */
/*   Updated: 2022/12/09 20:30:55 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pxdown(unsigned int nbr, int fd)
{	
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_pxdown(nbr / 16, fd);
		count += ft_pxdown(nbr % 16, fd);
	}
	else
	{
		if (nbr < 10)
			count += ft_putchar_fd(nbr + 48, fd);
		else
			count = count + ft_putchar_fd("0123456789abcdef" [nbr], fd);
	}
	return (count);
}
