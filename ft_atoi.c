/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:35:17 by gbarone           #+#    #+#             */
/*   Updated: 2023/06/25 23:30:11 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi(const char *str)
{
	int	neg;
	int	i;

	i = 0;
	neg = 0;
	while (*str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if (neg % 2 != 0)
		i = i * -1;
	return (i);
}
/*
int main()
{
    char* s1 = "000";   
    char* s2 = "+023";
    char* s3 = " -+0123aa";
    char* s4 = "-1203 123";
    
    int num1 = ft_atoi(s1);
    int num2 = ft_atoi(s2);
    int num3 = ft_atoi(s3);
    int num4 = ft_atoi(s4);

    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    printf("%d\n", num4);

    return 0;
}*/
