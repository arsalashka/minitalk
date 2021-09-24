/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:29:31 by maearly           #+#    #+#             */
/*   Updated: 2021/07/13 18:29:33 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*get_msg(t_status status)
{
	if (status == ARGUMENTS)
		return ("Error! Number of arguments isn't 3.\n");
	else if (status == PUSH)
		return ("Error! Send message error.\n");
	else if (status == FEEDBACK)
		return ("Error! server not responding.\n");
	else if (status == LONG_MSG)
		return ("Error! Too long message.\n");
	return ("Error! Unknown error.");
}

int	ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (*(str + i) == '\n'
		|| *(str + i) == '\t'
		|| *(str + i) == '\r'
		|| *(str + i) == '\v'
		|| *(str + i) == '\f'
		|| *(str + i) == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
		num = num * 10 + (*(str + i++) - '0');
	return (num * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	error(t_status status)
{
	char	*msg;

	msg = get_msg(status);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
