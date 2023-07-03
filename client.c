/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:50 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/03 18:22:53 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sender(char message, int PID)
{
	int	b;

	b = 0;
	while (message != 0)
	{
		if (message & 1)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(100);
		message >>= 1;
		b++;
	}
	while (b < 8)
	{
		kill(PID, SIGUSR2);
		usleep(100);
		b++;
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
			ft_sender(*s, PID);
			s++;
		}
		else
		{
			ft_sender(0, PID);
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
		ft_sender(*mssg++, p);
	ft_sender(0, p);
	s_handler(0);
	free (cp);
	return (0);
}
/*
Client-side
    Implementation of a communication protocol using signals

                 Functions:
 
                      check command-line arguments bugs(🐛);
                      handle received signals s_handler(📶);
                      to send messages ft_sender() and p_sender(📩);
                 Main:
                      function validates arguments,registers the signal handler, sends messages.
..
*/