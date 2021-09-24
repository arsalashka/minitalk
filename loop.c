/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:42:51 by maearly           #+#    #+#             */
/*   Updated: 2021/07/14 16:42:52 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_printer(t_data *data, int i)
{
	ft_putstr_fd(data->buf, 1);
	write(1, "\n", 1);
	ft_bzero(data->buf, i);
	kill(data->pid_client, SIGUSR1);
	data->pid_client = 0;
}

void	ft_loop(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		pause();
		if (data->index == 8)
		{
			while (data->buf[i] && i < CHAR_LIMIT)
				i++;
			if (i == CHAR_LIMIT)
				error(LONG_MSG);
			if (data->chr == 0)
				ft_printer(data, i);
			data->buf[i] = data->chr;
			data->chr = 0;
			data->index = 0;
			i = 0;
		}
	}
}
