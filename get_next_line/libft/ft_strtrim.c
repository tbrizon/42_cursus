/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:16:34 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 14:16:38 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une copie de la chaine sans les
**	espaces blancs au debut et a la fin de cette chaine.
**	On considere comme espaces blancs les caractères ’ ’, ’\n’ et ’\t’.
**	Si s ne contient pas d’espaces blancs au debut ou a la fin, la fonction
**	renvoie une copie de s.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strtrim(char const *s)
{
	char const *end;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	end = s + ft_strlen(s) - 1;
	while (*end == ' ' || *end == '\t' || *end == '\n')
		end--;
	return (ft_strsub(s, 0, end - s + 1));
}
