/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 11:57:15 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 11:57:16 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strncmp() functions lexicographically compare the null-terminated
**	strings s1 and s2.
**	-------------------------------------------------------------------------
**	The strncmp() function compares not more than n characters.  Because
**	strncmp() is designed for comparing strings rather than binary data,
**	characters that appear after a `\0' character are not compared.
**		RETURN VALUES
**	The strncmp() functions return an integer greater than, equal to, or less
**	than 0, according as the string s1 is greater than, equal to, or less than
**	the string s2.  The comparison is done using unsigned characters,
**	so that `\200' is greater than `\0'.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*str1 == *str2 && *str1 && --n)
	{
		str1++;
		str2++;
	}
	return ((int)(*str1 - *str2));
}
