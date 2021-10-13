/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:28:58 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/13 13:31:40 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_char(int signal, siginfo_t *siginfo, void *context)
{
	static char		c = 0;
	static int		shift = 7;

	context = NULL;
	if (signal == SIGUSR1)
		c = (c ^ (1 << shift));
	shift--;
	if (shift < 0)
	{
		write(1, &c, 1);
		shift = 7;
		c = 0;
	}
	usleep(40);
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %i\n", getpid());
	sa.sa_sigaction = &receive_char;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
