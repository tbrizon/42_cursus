/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:57:50 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 13:57:51 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une chaine de caracteres terminee
**	par un ’\0’ resultant de la concatenation de s1 et s2.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len_total;

	if (!s1 || !s2)
		return (NULL);
	len_total = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = ft_strnew(len_total)))
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
