/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:58:33 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/03 12:58:34 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The memchr() function locates the first occurrence of c (converted to
**	an unsigned char) in string s.
**		RETURN VALUES
**	The memchr() function returns a pointer to the byte located, or NULL
**	if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buffer;
	unsigned char	oct;

	oct = c;
	buffer = (unsigned char *)s;
	while (n)
	{
		if (*buffer == oct)
			return (buffer);
		buffer++;
		n--;
	}
	return (0);
}
