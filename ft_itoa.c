/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:53:20 by gbarone           #+#    #+#             */
/*   Updated: 2022/10/20 17:53:21 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_len(int nbr)
{
	int len;

	len = 0;
	len = (nbr <= 0 ? 1 : 0);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*alpha;

	sign = (n < 0 ? 1 : 0);
	alpha = NULL;
	len = ft_len(n);
	nbr = (n < 0 ? -n : n);
	if ((alpha = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	alpha[len--] = '\0';
	while (len >= 0)
	{
		alpha[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (sign == 1)
		alpha[0] = '-';
	return (alpha);
}



/*
static int	ft_mbcount(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_reverse( long int n, char *k)
{
	size_t		y;

	y = ft_mbcount(n);
	k[y] = '\0';
	if (n == 0)
		k[0] = '0';
	if (n < 0)
	{
		k[0] = '-';
		n *= -1;
	}
	y--;
	while (n != 0)
	{
		k[y] = (n % 10) + 48;
		n /= 10;
		y--;
	}
	return (k);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	y;

	y = size * count;
	if (count != 0 && size != y / count)
		return (NULL);
	p = (void *)malloc(y);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, y);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*r;

	r = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		r[i] = '\0';
		i++;
		n--;
	}
}


char	*ft_itoa(int n)
{
	char		*k;
	size_t		f;
	long int	l;

	l = n;
	f = ft_mbcount(l);
	k = ft_calloc((f + 1), sizeof(char));
	if (!k)
		return (NULL);
	ft_reverse(l, k);
	return (k);
}*/
