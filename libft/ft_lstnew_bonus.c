/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:58:16 by daafonso          #+#    #+#             */
/*   Updated: 2025/03/21 18:35:51 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

/*int	main(void)
{
	t_list	*list = ft_lstnew(ft_strdup("Hello"));
	printf("%s\n", (char *)list->content);
	free(list->content);
	free(list);
	return (0);
}*/
//BUT: ajouter du contenu a une liste et retourner la liste
//list->next = NULL marque la fin de la liste(similaire '\0')
