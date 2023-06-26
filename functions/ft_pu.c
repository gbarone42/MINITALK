/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:49:44 by gbarone           #+#    #+#             */
/*   Updated: 2023/06/26 16:36:40 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pu(unsigned int num, int fd)
{
	int					count;
	long long unsigned	n;

	n = (long long unsigned)num;
	count = 0;
	if (n > 9)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10 + 48), fd);
	return (count);
}
