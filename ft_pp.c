/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:07:26 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/11 18:09:36 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pp(uintptr_t nbr, int fd)
{	
	int	count;	

	count = 0;
	if (!nbr)
	{
		count = ft_putstr_fd("(nil)", fd);
		return (5);
	}
	else
	{
		write (1, "0x", 2);
		count = 2;
		count += ft_putnbr_base_fd(nbr, fd);
	}
	return (count);
}
/*
int	main(void)
{	
	char	*a = "ciao";
	
	ft_printf("%p\n", a);

}*/
