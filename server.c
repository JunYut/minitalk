/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:23:23 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/05 15:21:18 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/c_libft.h"

void handle_sigint(int sig)
{
    static char c;
	static int i;

	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
	if (i < 8)
	{
		c += (sig == SIGUSR2) << i++;
	}
}

int main()
{
	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		ft_printf("Waiting for signal...\n");
		signal(SIGUSR1, handle_sigint);
		signal(SIGUSR2, handle_sigint);
		pause();
	}

    return 0;
}