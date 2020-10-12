/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:38:10 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/09 17:38:11 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Prend en parametre l’adresse d’un pointeur sur un maillon et libere la
**	memoire du contenu de ce maillon avec la fonction del passee en parametre
**	puis libere la memoire du maillon en lui meme avec free(3).
**	La memoire du champ next ne doit en aucun cas etre liberee.
**	Pour terminer, le pointeur sur le maillon maintenant libere doit etre
**	mis a NULL (de maniere similaire a la fonction ft_memdel).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst && alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
