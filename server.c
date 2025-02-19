/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:25 by daafonso          #+#    #+#             */
/*   Updated: 2025/02/19 22:45:55 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*buffer = NULL;;

void	handle_message(char c)
{
	char		*temp;

	if (!buffer)
		buffer = ft_strdup("");
	temp = ft_strjoin(buffer, (char []){c, '\0'});
	free(buffer);
	buffer = temp;
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int	bit_acc;
	static int	bit_count;
	char		c;

	(void)context;
	if (bit_count == 0)
		bit_acc = 0;
	bit_acc = bit_acc << 1;
	if (signal == SIGUSR1)
		bit_acc |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		c = (char)bit_acc;
		handle_message(c);
		if (c == '\0')
		{
			ft_printf("%s\n", buffer);
			free(buffer);
			buffer = NULL;
		}
		bit_acc = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error only one argument is required!\n");
		return (1);
	}
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server's ID : %d\n", getpid());
	ft_printf("Waiting for a message...\n");
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
