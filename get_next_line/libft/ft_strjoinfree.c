/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:21:01 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/29 12:21:02 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une chaine de caracteres terminee
**	par un ’\0’ resultant de la concatenation de s1 et s2, puis free s1, s2 ou
**	les deux en fonction de la valeur de i. (1 => s1, 2 =>s2 3 => s1 et s2).
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strjoinfree(const char *s1, const char *s2, int i)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	if (!(dest = ft_strjoin(s1, s2)))
		return (NULL);
	if (i == 1 || i == 3)
		free((char *)s1);
	if (i == 2 || i == 3)
		free((char *)s2);
	return (dest);
}
