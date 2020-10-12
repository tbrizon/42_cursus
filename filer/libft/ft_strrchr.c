/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:27:19 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/03 18:40:16 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strrchr() function locates the last occurrence of c (converted to
**	a char) in the string pointed to by s.  The terminating null character
**	is considered to be part of the string; therefore if c is `\0', the
**	functions locate the terminating `\0'.
**		RETURN VALUES
**	The functions strrchr() return a pointer to the located character,
**	or NULL if the character does not appear in the string.
*/

char	*ft_strrchr(const	char *s, int c)
{
	char *str;

	str = (char *)s + ft_strlen(s);
	while (*str != c)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return (str);
}
