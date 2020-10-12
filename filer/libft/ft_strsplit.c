/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:57:10 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 15:57:11 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne un tableau de chaines de caracteres
**	(toutes terminees par un ’\0’, le tableau egalement) resultant de la
**	decoupe de s selon le caractere c.
**	Si l’allocation echoue, la fonction retourne NULL.
**	Exemple :
**	ft_strsplit("*salut*les***etudiants*", ’*’)
**	renvoie le tableau ["salut", "les", "etudiants"].
*/

static size_t	ft_word_nbr(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	len;
	size_t	i;

	if (!(s))
		return (NULL);
	len = ft_word_nbr(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	dst[len] = NULL;
	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (*s || (!*s && len))
			dst[i++] = ft_strndup(s - len, len);
	}
	return (dst);
}
