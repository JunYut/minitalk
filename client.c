/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:53:05 by we                #+#    #+#             */
/*   Updated: 2024/03/26 22:00:53 by we               ###   ########.fr       */
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
		g_confirm = 0;
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_confirm)
			pause();
	}
}

void	confirm(int signum)
{
	static int	i;

	if (i % 32 == 0 && i != 0)
		write(1, "\n", 1);
	ft_printf("Bit[%d] received\n", i++);
	g_confirm = 1;
	(void)signum;
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

int	main(int argc, char *argv[])
{
	if (argc != 3 || !is_pid(argv[1]))
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		return (1);
	}
	ft_printf("Client PID: %d\n", getpid());
	signal(SIGUSR2, confirm);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
