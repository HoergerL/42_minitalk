/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:25:54 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/13 13:32:56 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_char(int signal)
{
	static char		c = 0;
	static int		shift = 6;

	if (signal == SIGUSR1)
	{
		c = (c ^ (1 << shift));
	}
	shift--;
	if (shift < 0)
	{
		write(1, &c, 1);
		shift = 6;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %i\n", getpid());
	sa.sa_handler = &receive_char;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
