/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:41:19 by daafonso          #+#    #+#             */
/*   Updated: 2025/03/21 18:37:42 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "aryawwwbw";
	int	c = 'w';
	printf("%s", ft_strrchr(str, c));
	return (0);
}*/
//BUT: Trouve le dernier caractere d'une string
//Parcourir a l'envers
//int i car i = -1 a la fin de la boucle
//Conversion int -> char pour check -128 et 127
