/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:44 by tiun-yu           #+#    #+#             */
/*   Updated: 2024/03/26 17:40:40 by we               ###   ########.fr       */
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

	struct sigaction	sig1;
	sig1.sa_sigaction = receive;
	sigemptyset(&sig1.sa_mask);
	sig1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig1, NULL);

	while (1)
	{
		pause();
	}

    return 0;
}

void receive(int sig, siginfo_t *info, void *ucontext_t)
{
	static int c;
	static int i = 0;

	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	else
		c += (sig == SIGUSR2) << ++i;
	kill(info->si_pid, SIGUSR1);

	(void)ucontext_t;
}
