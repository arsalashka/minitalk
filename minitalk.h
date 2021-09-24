/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maearly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:53:19 by maearly           #+#    #+#             */
/*   Updated: 2021/07/13 15:53:21 by maearly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

# define CHAR_LIMIT 1024

typedef enum e_status
{
	ARGUMENTS,
	PUSH,
	FEEDBACK,
	LONG_MSG
}	t_status;

typedef struct s_data
{
	char			buf[CHAR_LIMIT];
	unsigned char	chr;
	int				index;
	int				pid_client;
}	t_data;

int		ft_atoi(const char *str);
void	error(t_status status);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_loop(t_data *data);
#endif
