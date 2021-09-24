/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:52:30 by maearly           #+#    #+#             */
/*   Updated: 2021/07/15 17:52:32 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	push_char(unsigned char c, int pid_server)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit >= 1)
	{
		if (bit & c)
		{
			if (kill(pid_server, SIGUSR1) == -1)
				return (1);
		}
		else
		{
			if (kill(pid_server, SIGUSR2) == -1)
				return (1);
		}
		bit /= 2;
		usleep(50);
	}
	return (0);
}

void	answer_handler(int sig, siginfo_t *info, void *cont)
{
	(void)sig;
	(void)info;
	(void)cont;
	ft_putstr_fd("Message received!\n", 1);
	exit(0);
}

void	init(struct sigaction *sa, char **msg, int *pid_s, char **av)
{
	sa->sa_sigaction = &answer_handler;
	sa->sa_flags = SA_SIGINFO;
	*msg = av[2];
	*pid_s = ft_atoi(av[1]);
	sigaction(SIGUSR1, sa, NULL);
}

int	main(int ac, char **av)
{
	struct sigaction	answer;
	char				*msg;
	int					pid_server;
	int					i;

	i = -1;
	if (ac != 3)
		error(ARGUMENTS);
	init(&answer, &msg, &pid_server, av);
	while (msg[++i])
	{
		if (push_char(msg[i], pid_server))
			error(PUSH);
	}
	if (push_char(0, pid_server))
		error(PUSH);
	sleep(4);
	error(FEEDBACK);
}
