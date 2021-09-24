/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:53:01 by maearly           #+#    #+#             */
/*   Updated: 2021/07/13 15:53:04 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	one_handler(int sig, siginfo_t *info, void *cont)
{
	unsigned char	byte;

	(void)cont;
	(void)sig;
	byte = 128;
	g_data.chr = byte >> g_data.index | g_data.chr;
	g_data.index++;
	if (!g_data.pid_client)
		g_data.pid_client = info->si_pid;
}

void	zero_handler(int sig, siginfo_t *info, void *cont)
{
	(void)cont;
	(void)sig;
	g_data.index++;
	if (!g_data.pid_client)
		g_data.pid_client = info->si_pid;
}

void	init(struct sigaction *one, struct sigaction *zero)
{
	one->sa_sigaction = &one_handler;
	zero->sa_sigaction = &zero_handler;
	one->sa_flags = SA_SIGINFO;
	zero->sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, one, NULL);
	sigaction(SIGUSR2, zero, NULL);
	ft_bzero((void *)g_data.buf, CHAR_LIMIT);
	g_data.chr = 0;
	g_data.index = 0;
	g_data.pid_client = 0;
}

int	main(void)
{
	struct sigaction	one;
	struct sigaction	zero;

	init(&one, &zero);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	ft_loop(&g_data);
	return (0);
}
