/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:49:36 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/03/05 15:53:20 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/Libft.h"

int *dec_to_bit(int dec)
{
	static int bits[8];
	for(int i = 0; i < 8; ++i)
		bits[i] = (dec >> i) & 1;
	return (bits);
}

int	bit_to_dec(int *bits)
{
	int c = 0;
	for (int i = 0; i < 8; i++)
		c += bits[i] << i;
	return (c);
}

int	main(void)
{
	ft_printf("%c\n", bit_to_dec(dec_to_bit('a')));
}
