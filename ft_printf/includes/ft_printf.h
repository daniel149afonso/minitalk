/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:43:21 by daniel149af       #+#    #+#             */
/*   Updated: 2024/10/29 16:42:52 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>//macros variables
# include <unistd.h>

int	ft_printf(const char *str, ...);

//Fonctions de format
int	ft_printstr(char *s);
int	ft_strlen_v2(char *s);
int	ft_printnbr(int nb);
int	ft_printptr(unsigned long long ptr);
int	ft_printhex(unsigned int nb, char c);
int	ft_print_unsigned(unsigned int nb);

#endif
