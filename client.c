/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:53:05 by we                #+#    #+#             */
/*   Updated: 2024/03/11 10:16:26 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/c_libft.h"

volatile sig_atomic_t	g_confirm = 0;

void	send_message(int pid, char *message);
void	send_bit(int pid, int c);
void	confirm(int signum);
int		is_pid(char *str);

void	send_message(int pid, char *message)
{
	while (*message != 0)
	{
		send_bit(pid, *message++);
	}
	send_bit(pid, '\n');
}

void	send_bit(int pid, int c)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		signal(SIGUSR2, confirm);
		g_confirm = 0;
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_confirm)
			pause();
	}
}

int	is_pid(char *str)
{
	int	pid;

	pid = ft_atoi(str);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	if (kill(pid, 0) == -1)
		return (0);
	return (1);
}

void	confirm(int signum)
{
	write(1, "Bit received\n", 13);
	g_confirm = 1;
	(void)signum;
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || !is_pid(argv[1]))
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		return (1);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
