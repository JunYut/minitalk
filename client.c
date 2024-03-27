/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:20:51 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/27 10:33:30 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/c_libft.h"

void	send_bits(int pid, char c);
void	confirm(int signal);

int	main(int argc, char *argv[])
{
	int	i;

	i = -1;
	while (argv[2][++i])
	{
		signal(SIGUSR1, confirm);
		signal(SIGUSR2, confirm);
		send_bits(ft_atoi(argv[1]), argv[2][i]);
	}
	send_bits(ft_atoi(argv[1]), '\n');
	ft_printf("All signals sent\n");
	(void)argc;
	return (0);
}

void	send_bits(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	confirm(int signal)
{
	static int	i;

	ft_printf("Char[%d] received!\n", i++);
	(void)signal;
}
