/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:34:33 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 13:34:34 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne la copie d’un troncon de la chaine
**	de caracteres. Le troncon commence a l’index start et a pour longueur len.
**	Si start et len ne designent pas un troncon de chaine valide,
**	le comportement est indetermine.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*copy;

	if (!s)
		return (NULL);
	if (!(copy = ft_strnew(len)))
		return (NULL);
	ft_strncpy(copy, s + start, len + 1);
	copy[len] = '\0';
	return (copy);
}
