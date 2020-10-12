/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:44:37 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/09 19:44:38 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Parcourt la liste lst en appliquant la fonction f a chaque maillon et
**	cree une nouvelle liste avec malloc(3) resultant des applications
**	successives.
**	Si une allocation echoue, la fonction renvoie NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *start;

	if (lst && f)
	{
		if (!(tmp = (*f)(lst)))
			return (NULL);
		start = tmp;
		lst = lst->next;
		while (lst)
		{
			if (!(tmp->next = (*f)(lst)))
				return (NULL);
			lst = lst->next;
			tmp = tmp->next;
		}
		return (start);
	}
	return (NULL);
}
