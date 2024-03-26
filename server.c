/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:59 by we                #+#    #+#             */
/*   Updated: 2024/03/26 22:11:37 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include <signal.h>
#include <unistd.h>
#include "libft/c_libft.h"

void	receive(int signum, siginfo_t *info, void *context)
{
	static int	pid;
	static int	c;
	static int	i;

	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		i = 0;
	}
	if (i == 31)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c += (signum == SIGUSR1) << i++;
	kill(info->si_pid, SIGUSR2);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = receive;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
}
