/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:00:49 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/02 17:00:51 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The memccpy() function copies bytes from string src to string dst.
**	If the character c (as converted to an unsigned char) occurs in the
**	string src, the copy stops and a pointer to the byte after the copy
**	of c in the string dst is returned.
**	Otherwise, n bytes are copied, and a NULL pointer is returned.
**	-------------------------------------------------------------------------
**	The source and destination strings should not overlap,
**	as the behavior is undefined.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*sr;
	unsigned char		*dst;

	sr = src;
	dst = dest;
	i = 0;
	while (i < n)
	{
		dst[i] = sr[i];
		if (sr[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
