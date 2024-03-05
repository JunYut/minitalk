/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:36 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/05 10:56:36 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/c_libft.h"

void	send(int pid, const char *message)
{
	if (message == NULL)
		return ;
	while (*message != 0);
}

int	main(void)
{
	int num;

	num = 3;
	for(int j = 0; j < 256; ++j)
	{
		ft_printf("%d: ", j);
		for(int i = 0; i < 8; ++i)
			ft_printf("%d", (j >> i) & 1);
		ft_printf("\n");
	}
}
