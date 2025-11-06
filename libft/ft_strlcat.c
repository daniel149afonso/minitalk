/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:37:43 by daniel149af       #+#    #+#             */
/*   Updated: 2025/03/21 18:37:17 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*int	main()
{
	char dest[] = "Hello";
	char src[] = "Hello";

	printf("Taille totale de dest a la fin: %lu\n", ft_strlcat(dest, src, 10));
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	return (0);
}*/
//Concatene une string dans une autre + '\0'
// size = strin + '\0' evite les erreurs de depassement
