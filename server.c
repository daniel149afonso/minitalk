/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:25 by daafonso          #+#    #+#             */
/*   Updated: 2025/02/10 19:26:11 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_binary(int num)
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

	bit_acc = bit_acc << 1; //décalage à gauche
	if (signal == SIGUSR1)
		bit_acc |= 1; //ajoute 1 (si SIGUSR1)
	bit_count++;
    print_binary(bit_acc);
	if (bit_count == 8)
	{
		ft_printf("Character received: %c", bit_acc);
		bit_acc = 0;
		bit_count = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("Server's ID : %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
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
