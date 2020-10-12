/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:45:14 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/04 15:45:15 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strnstr() function locates the first occurrence of the null-terminated
**	string s2 in the string s1, where not more than n characters are searched.
**	Characters that appear after a `\0' character are not searched.
**	Since the strnstr() function is a FreeBSD specific API, it should only
**	be used when portability is not a concern.
**		RETURN VALUES
**	If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1,
**	NULL is returned; otherwise a pointer to the first character of the
**	first occurrence of s2 is returned.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while (*s1 && len <= n)
	{
		if (ft_strncmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
