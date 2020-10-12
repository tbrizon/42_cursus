/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:43:53 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/03 18:38:02 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strchr() function locates the first occurrence of c (converted to
**	a char) in the string pointed to by s.  The terminating null character
**	is considered to be part of the string; therefore if c is `\0', the
**	functions locate the terminating `\0'.
**		RETURN VALUES
**	The functions strchr() return a pointer to the located character,
**	or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}
