/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 01:10:38 by gbarone           #+#    #+#             */
/*   Updated: 2023/06/26 16:32:37 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(uintptr_t nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_base_fd(nbr / 16, fd);
		count += ft_putnbr_base_fd(nbr % 16, fd);
	}
	else
		count = count + ft_putchar_fd("0123456789abcdef"[nbr], fd);
	return (count);
}
