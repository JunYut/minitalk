/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:44 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/26 12:48:26 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include "libft/Libft.h"

void receive(int sig, siginfo_t *info, void *ucontext);

int main()
{
	ft_printf("Server PID: %d\n", getpid());

	struct sigaction	sa;
	sa.sa_sigaction = receive;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
	}

    return 0;
}

void receive(int sig, siginfo_t *info, void *ucontext_t)
{
	static int PID;
	static int i;

	if (info->si_pid != PID)
		i = 0;
	PID = info->si_pid;
	ft_printf("Signal[%d] received: %d\n", ++i, sig);
	ft_printf("Client PID: %d\n", info->si_pid);
	kill(info->si_pid, SIGUSR1);

	(void)ucontext_t;
	return;
}
