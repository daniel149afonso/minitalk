/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:24:25 by daafonso          #+#    #+#             */
/*   Updated: 2025/02/02 20:54:00 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handle_signal(int signal)
{
    printf("Received: %d\n", signal);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    printf("Server's ID : %d\n", getpid());
    //signal(SIGUSR1, handle_signal);
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    return (0);
}