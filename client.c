/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:37 by daafonso          #+#    #+#             */
/*   Updated: 2025/02/17 16:45:38 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(int pid, char *msg)
{
	int		bit;
	int		i;
	char	c;
	int		len;

	i = 0;
	len = ft_strlen_v2(msg) + 1;
	while (i < len)
	{
		bit = 7;
		c = msg[i];
		while (bit >= 0)
		{
			if (((c >> bit) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
			bit--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_send_message(pid, argv[2]);
	}
	return (0);
}
//
