/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:36 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/26 13:00:09 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/Libft.h"

void	receive(int sig, siginfo_t *info, void *ucontext);

int	main(int argc, char *argv[])
{
	ft_printf("Client PID: %d\n", getpid());

	struct sigaction	action;
	action.sa_sigaction = receive;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);

	kill(ft_atoi(argv[1]), SIGUSR1);
	while (1)
		pause();

	ft_printf("Client exit\n");

	(void)argc;
	(void)argv;
}

void	receive(int sig, siginfo_t *info, void *ucontext)
{
	static int i;

	ft_printf("Signal[%d] received\n", ++i);
	ft_printf("Server PID: %d\n", info->si_pid);

	for (int i = 0; i < 10000; i++)
	{
		kill(info->si_pid, SIGUSR1);
	}

	(void)sig;
	(void)ucontext;
}
