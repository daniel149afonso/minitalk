/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:37 by daafonso          #+#    #+#             */
/*   Updated: 2025/02/14 15:52:00 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(int pid, char *msg)
{
	int		bit;
	int		i;
	char	c;

	i = 0;
	while (msg[i])
	{
		bit = 7;
		c = msg[i];
		while (bit >= 0)
		{
			if (((c >> bit) & 1) == 1)
			{
				kill(pid, SIGUSR1);
				usleep(100);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(100);
			}
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
