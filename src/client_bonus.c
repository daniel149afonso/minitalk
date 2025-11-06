/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:37 by daafonso          #+#    #+#             */
/*   Updated: 2025/11/07 00:07:15 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_client	g_client = {0, 0};

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
		g_client.bit_confirmed = 1;
	else if (signal == SIGUSR2)
		g_client.message_confirmed = 1;
	else
		ft_printf("⚠️ Signal inattendu reçu : %d\n", signal);
}

void	ft_send_signal(int pid, char c, int *bit)
{
	int	signal;

	if (((c >> *bit) & 1) == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
	{
		ft_printf("Error: Failed to send signal to server\n");
		exit(EXIT_FAILURE);
	}
	while (!g_client.bit_confirmed)
		pause();
	g_client.bit_confirmed = 0;
}

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
			g_client.bit_confirmed = 0;
			ft_send_signal(pid, c, &bit);
			bit--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error: The correct format is %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_send_message(pid, argv[2]);
	while (!g_client.message_confirmed)
		pause();
	ft_printf("✅ Message delivered!\n");
	return (0);
}
//Linux ne gere pas la fille d'attente des signaux a nous de le faire
//Afin deviter que des char se chevauchent ou soient perdus
//A choix:
//pause(): + Simplicité, bloque le programme, pas de consommation CPU.
//- Peut bloquer indéfiniment si SIGUSR1 est perdu.
//--------------------------------------
//usleep(50): + Vérification régulière, pas de blocage.
// -Boucle active (léger gaspillage CPU).