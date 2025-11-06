/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:18:56 by daafonso          #+#    #+#             */
/*   Updated: 2025/11/06 18:11:06 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/includes/ft_printf.h"
# include "libft/libft.h"

typedef struct s_client
{
	int	bit_confirmed;
	int	message_confirmed;
}	t_client;
#endif
