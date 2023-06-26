/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:50 by gbarone           #+#    #+#             */
/*   Updated: 2023/06/26 16:56:01 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sender(char message, int PID)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if ((message >> b) & 1)
			kill(PID, SIGUSR1);
		else
			kill(PID, SIGUSR2);
		usleep(100);
		b++;
	}
}

void	p_sender(char *s, int PID)
{
	int	pos;

	pos = 0;
	while (pos < 8)
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

void	s_handler(int sig)
{
	static int	status;

	if (sig == SIGUSR1)
	{
		write(1, "→ \n Sending message \n→", 27);
		status = sig;
	}
	else if (sig == SIGUSR2)
	{
		status = sig;
		write(1, "→ \n Message received \n→→→\n", 35);
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
	char	*message;
	int		p;
	char	*cp;

	signal(SIGUSR1, s_handler);
	signal(SIGUSR2, s_handler);
	if (bugs(ac, av))
		exit (1);
	p = ft_atoi(av[1]);
	cp = ft_itoa(getpid());
	p_sender(cp, p);
	message = av[2];
	while (*message)
		ft_sender(*message++, p);
	ft_sender(0, p);
	s_handler(0);
	free (cp);
	return (0);
}
