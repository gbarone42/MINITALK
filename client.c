/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:50 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/05 00:14:56 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender(char message, int PID)
{
	int	bit_tracker;
	int	max_pos;

	bit_tracker = 0;
	max_pos = 8;
	while (message != 0)
	{
		if (message & 1)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(1000);
		message >>= 1;
		bit_tracker++;
	}
	while (bit_tracker < max_pos)
	{
		kill(PID, SIGUSR2);
		usleep(1000);
		bit_tracker++;
	}
}

void	p_sender(char *s, int PID)
{
	int	pos;
	int	max_pos;

	pos = 0;
	max_pos = 8;
	while (pos < max_pos)
	{
		if (*s)
		{
			sender(*s, PID);
			s++;
		}
		else
		{
			sender(0, PID);
		}
		pos++;
	}
}

void	s_handler(int signal)
{
	static int	status;

	if (signal == SIGUSR1)
	{
		ft_printf("→ \n ..Sending.. \n→");
		status = signal;
	}
	else if (signal == SIGUSR2)
	{
		status = signal;
		ft_printf("→ \n ..Received.. \n→→→\n");
	}
	else
	{
		if (status == 0)
			ft_printf(" ⚠️ ERROR: ⚠️ ⚠️ \n ⚠️ ...check the PIDocchio...⚠️ \n");
	}
}

int	bugs(int argc, char **argv)
{
	char	*pids;

	pids = argv[1];
	if (argc > 3)
	{
		ft_printf("ERROR: 🐜 🐜 🐜 🐜 🐜 🐜 🐜 🐜 🐜  \n ...Too many argumentss\n");
		return (1);
	}
	if (argc < 3)
	{
		ft_printf("BUG... liteally 🐛 : 💩😂 \n Too few argumentss...\n");
		return (1);
	}
	while (*pids)
	{
		if (!ft_isdigit(*pids))
		{
			ft_printf(" 🐛🐛🐛 \n💩🙃 INVALID PIDocchio/.../digit only/.../\n");
			return (1);
		}
		pids++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	char	*mssg;
	int		p;
	char	*cp;

	if (bugs(ac, av))
		exit (1);
	signal(SIGUSR1, s_handler);
	signal(SIGUSR2, s_handler);
	p = ft_atoi(av[1]);
	cp = ft_itoa(getpid());
	p_sender(cp, p);
	mssg = av[2];
	while (*mssg)
		sender(*mssg++, p);
	sender(0, p);
	s_handler(0);
	free (cp);
	return (0);
}
