/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:14:37 by gbarone           #+#    #+#             */
/*   Updated: 2022/11/11 17:22:49 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ps(char *stringa, int fd)
{
	int	count;

	count = 0;
	if (stringa == NULL)
	{
		count = ft_putstr_fd("(null)", fd);
		return (count);
	}
	else
	{
		count = ft_putstr_fd(stringa, fd);
		return (count);
	}
}
