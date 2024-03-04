/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:36 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/04 15:39:20 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/c_libft.h"

void	send(int pid, const char *message)
{
	if (message == NULL)
		return ;
	while (*message != 0)
}

int	main(void)
{
	ft_printf("pid: %d\n", getpid());
	ft_printf("SIGUSR1: %d\n", SIGUSR1);
	ft_printf("SIGUSR2: %d\n", SIGUSR2);
}
