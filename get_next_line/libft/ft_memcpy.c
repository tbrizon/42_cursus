/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:09:30 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/02 18:09:31 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The memcpy() function copies n bytes from memory area src to memory
**	area dst.  If dst and src overlap, behavior is undefined.
**	Applications in which dst and src might overlap should use memmove(3)
**	instead.
**		RETURN VALUES
**	The memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*source;
	char			*dst;
	unsigned int	i;

	i = 0;
	source = src;
	dst = dest;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}
