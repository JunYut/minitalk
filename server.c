/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:48 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/27 10:23:32 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/Libft.h"

void	receive(int sig, siginfo_t *info, void *ucontext_t);

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = receive;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}

void	receive(int sig, siginfo_t *info, void *ucontext_t)
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
	if (sig == SIGUSR1)
		c |= (0x01 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	(void)ucontext_t;
}
