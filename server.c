/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:25 by daafonso          #+#    #+#             */
/*   Updated: 2025/02/17 17:03:41 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_binary(int num)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_printf("%d", (num >> i) & 1);
		i--;
	}
	ft_printf("\n");
}

void	handle_signal(int signal)
{
	static int	bit_acc;
	static int	bit_count;
	char		c;

	bit_acc = bit_acc << 1;
	if (signal == SIGUSR1)
		bit_acc |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		c = bit_acc;
		if (c != '\0')
			ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\nMessage received!\n\n");
		bit_acc = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error only one argument is required!\n");
		return (1);
	}
	ft_printf("Server's ID : %d\n", getpid());
	ft_printf("Waiting for a message...\n");
	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
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
