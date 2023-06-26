/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:06:08 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/14 18:06:14 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	c;
	int		count;

	c = n;
	count = 0;
	if (c < 0)
	{
		write(fd, "-", 1);
		count = 1;
		c = c * -1;
	}
	if (c > 9)
		count += ft_putnbr_fd(c / 10, fd);
	count += ft_putchar_fd(c % 10 + 48, fd);
	return (count);
}
/*
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}*/
