/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 21:07:36 by daniel149af       #+#    #+#             */
/*   Updated: 2025/03/21 18:37:21 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*int	main(void)
{
	size_t	n = 4;
	char	dest[n];
	const char	src[] = "Bonjour";
	printf("Taille totale de src: %lu\n", ft_strlcpy(dest, src, n));
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Length of src: %zu\n", n);
	return (0);
}*/
//BUT: copie une chaîne de caractères dans une autre
//avec un espace pour '\0'
//permet deviter les depassement de memoire
