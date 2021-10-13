/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhoerger <lhoerger@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:28:58 by lhoerger          #+#    #+#             */
/*   Updated: 2021/10/13 13:34:50 by lhoerger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_input_error(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 3 )
	{
		ft_printf("Wrong number of inputs\n");
		exit(1);
	}
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i])))
		{
			ft_printf("The process ID is wrong");
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	shift;

	i = 0;
	check_input_error(argc, argv);
	while (argv[2][i] != '\0')
	{
		shift = 6;
		while (shift >= 0)
		{
			if ((argv[2][i] & (1 << shift)) > 0)
				kill(ft_atoi(argv[1]), SIGUSR1);
			else
				kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(55);
			shift--;
		}
		i++;
		usleep(50);
	}
	return (0);
}
