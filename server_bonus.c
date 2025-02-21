/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:25 by daafonso          #+#    #+#             */
/*   Updated: 2025/02/21 21:40:38 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_message(char c, char **message)
{
	char	*buffer;

	if (!*message)
	{
		*message = ft_strdup("");
		if (!*message)
		{
			ft_printf("Error: Failed to allocate the message.\n");
			exit(EXIT_FAILURE);
		}
	}
	buffer = ft_strjoin(*message, (char []){c, '\0'});
	if (!buffer)
	{
		free(*message);
		ft_printf("Error: Failed to allocate the buffer\n.");
		exit(EXIT_FAILURE);
	}
	free(*message);
	*message = buffer;
}

void	ft_display_message(siginfo_t *info, char **message)
{
	ft_printf("%s\n", *message);
	free(*message);
	*message = NULL;
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_printf("Error: Failed to send confirmation message.\n");
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bit_acc = 0;
	static int	bit_count = 0;
	static char	*message = NULL;
	char		c;

	(void)context;
	bit_acc = bit_acc << 1;
	if (signal == SIGUSR1)
		bit_acc |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		c = (char)bit_acc;
		handle_message(c, &message);
		if (c == '\0')
			ft_display_message(info, &message);
		bit_acc = 0;
		bit_count = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_printf("Error: Failed to send confirmation char.\n");
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server's ID : %d\n", getpid());
	ft_printf("Waiting for a message...\n");
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

//BUT: Gestionnaire de signaux
//boucle infinie avec pause pour garder le serveur actif
//mais en veille en attente d'un signal
//pause(); économise du CPU en évitant une boucle inutile
//------------------------
//Bit_acc: accumule les bits au fur et a mesure qui represente une lettre
//Bit_count: va compter le nombre de bit jusqu'a 8 puis afficher
//la lettre correspondante
//-------------------------
//bit_acc = bit_acc << 1; //décalage à gauche ajoute par défaut 0
//bit_acc |= 1; //ajoute 1 (si SIGUSR1) remplace le 0 par defaut
//------------------------------------------------------------
//Utiliser sigaction() au lieu de signal() pour eviter la perte signaux
//sa.sa_flags = SA_SIGINFO; pour recuperer le PID du client