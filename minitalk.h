/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:50 by gbarone           #+#    #+#             */
/*   Updated: 2023/10/02 18:39:06 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

# include <stdarg.h>

# include <stddef.h>

# include <stdio.h>

# include <stdlib.h>

# include <unistd.h>

# include "functions/ft_printf.h"

char	*ft_itoa(int n);

int		ft_isdigit(int c);

int		ft_atoi(const char *str);

#endif

//thanks :)