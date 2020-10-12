/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <tbrizon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:34:33 by tbrizon           #+#    #+#             */
/*   Updated: 2019/09/10 11:18:01 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne la copie d’un troncon de la chaine
**	de caracteres. Le troncon commence a l’index start et a pour longueur len.
**	Si start et len ne designent pas un troncon de chaine valide,
**	le comportement est indetermine. o Est une option, si o = 1 on free s.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strsub(const char **s, unsigned int strt, size_t ln, int o)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!*s || !(new = ft_strnew(ln)))
		return (NULL);
	while (ln--)
		new[i++] = (*s)[strt++];
	if (o == 1)
		ft_memdel((void**)s);
	return (new);
}
