/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:29:27 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/10 20:29:29 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_formatspecifier(const char str, va_list *args)
{
	int	count;

	count = 0;
	if (str == '%')
		count += ft_putchar_fd('%', 1);
	else if (str == 'c')
		count += ft_putchar_fd(va_arg(*args, int), 1);
	else if (str == 's')
		count += ft_ps(va_arg(*args, char *), 1);
	else if (str == 'p')
		count += ft_pp(va_arg(*args, uintptr_t), 1);
	else if (str == 'x')
		count += ft_pxdown(va_arg(*args, unsigned int), 1);
	else if (str == 'X')
		count += ft_pxup(va_arg(*args, unsigned int), 1);
	else if (str == 'u')
		count += ft_pu(va_arg(*args, unsigned int), 1);
	else if (str == 'd' || str == 'i')
		count += ft_putnbr_fd(va_arg(*args, int), 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	if (!str)
		ft_putstr_fd("(null)", 1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_formatspecifier(str[i + 1], &args);
			i++;
		}		
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main()
{	
	//char p[ 10 ] = { 1, 1, 3};
	int c;
	unsigned int a = -12;
	//char *s = NULL;
	//int c2;
	c = 12;
	
	printf( "%X\n" , c);
	printf( "%x\n" , a);
	//c2 = printf( "%s", (char *)NULL );
	//printf("\n %d", c);
	//printf("\n %d", c2);
	
}*/
