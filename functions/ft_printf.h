/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:40:54 by gbarone           #+#    #+#             */
/*   Updated: 2023/06/25 23:21:14 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

char	*ft_itoa(int n);
int		ft_printf(const char *str, ...);
int		ft_pp(uintptr_t nbr, int fd);
int		ft_ps(char *stringa, int fd);
int		ft_pu(unsigned int num, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_base_fd(uintptr_t nbr, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_pxup(unsigned int nbr, int fd);
int		ft_pxdown(unsigned int nbr, int fd);
int		ft_formatspecifier(const char str, va_list *args);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_size(long long n, int base);

#endif
