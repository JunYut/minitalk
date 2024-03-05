/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:36 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/05 14:48:49 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/c_libft.h"

void	yeet(int pid, const char *message)
{
	int	i;

	if (message == NULL)
		return ;
	while (*message != 0)
	{
		i = -1;
		while (++i < 8)
		{
			kill(pid, *message << i & 1 ? SIGUSR2 : SIGUSR1);
		}
		++message;
	}
}

int	main(void)
{
	int	pid;

	ft_printf("Enter server PID: ");
	pid = ft_atoi(get_next_line(0));
	ft_printf("pid: %d\n", pid);
	yeet(pid, "Hello, world!");

	return (0);
}
