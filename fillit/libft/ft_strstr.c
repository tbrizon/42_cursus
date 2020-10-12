/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:03:59 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/04 12:04:00 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strrstr() function locates the last occurrence of the null-terminated
**	string s2 in the null-terminated string s1.
**		RETURN VALUES
**	If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1,
**	NULL is returned; otherwise a pointer to the first character of the
**	last occurrence of s2 is returned.
*/

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
