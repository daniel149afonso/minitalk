/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:02:32 by daafonso          #+#    #+#             */
/*   Updated: 2025/03/21 18:36:07 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	*str1;

	if (!dest && !src)
		return (NULL);
	i = 0;
	str = (unsigned char *)dest;
	str1 = (const unsigned char *)src;
	while (i < n)
	{
		str[i] = str1[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char		str[8];
	const char	*str1 = "ABCDEFGH";

	ft_memcpy(str, str1, 8);
	for(int i = 0; i < 8; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");
	return (0);
}*/
//BUT: copie un bloc de mémoire d'une source vers une destination
//dest: Un pointeur vers la zone de mémoire où les données doivent être copiées
//src: Un pointeur vers la zone de mémoire d'où les données doivent être copiées
//n : Le nombre d'octets à copier.
