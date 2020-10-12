/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:27:20 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/03 13:27:22 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The memcmp() function compares byte string s1 against byte string s2.
**	Both strings are assumed to be n bytes long.
**		RETURN VALUES
**	The memcmp() function returns zero if the two strings are identical,
**	otherwise returns the difference between the first two differing
**	bytes (treated as unsigned char values, so that `\200' is greater
**	than `\0', for example).  Zero-length strings are always identical.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
