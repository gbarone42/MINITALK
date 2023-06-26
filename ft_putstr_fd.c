/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:23:11 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/14 01:23:15 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
		count++;
	}
	return (count);
}
