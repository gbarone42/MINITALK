/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:48:50 by gbarone           #+#    #+#             */
/*   Updated: 2023/06/25 20:05:44 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sender(char str, int PID)
{
	int	wbit;

	wbit = 0;
	while (wbit < 8)
	{
		kill(PID, (str >> wbit) & 1 ? SIGUSR1 : SIGUSR2);
		usleep(100);
		wbit++;
	}
}

void	ft_pidsender(char *str, int PID)
{
	int	pos;

	pos = 0;
	while (pos < 8)
	{
		if (*str)
		{
			ft_sender(*str, PID);
			str++;
		}
		else
		{
			ft_sender(0, PID);
		}
		pos++;
	}
}

void	ft_getping(int sig)
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

int	ft_errno(int argc, char **argv)
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

int	main(int argc, char *argv[])
{
	char	*message;
	int		p;
	char	*cp;

	signal(SIGUSR1, ft_getping);
	signal(SIGUSR2, ft_getping);
	if (ft_errno(argc, argv))
		exit (1);
	p = ft_atoi(argv[1]);
	cp = ft_itoa(getpid());
	ft_pidsender(cp, p);
	message = argv[2];
	while (*message)
		ft_sender(*message++, p);
	ft_sender(0, p);
	ft_getping(0);
	free (cp);
	return (0);
}
