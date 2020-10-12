/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:41:29 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/02 13:41:31 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The memmove() function copies len bytes from string src to string dst.
**	The two strings may overlap; the copy is always done in a non-destructive
**	manner.
**		RETURN VALUES
**	The memmove() function returns the original value of dst.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*source;
	char		*dst;

	source = (const char *)src;
	dst = (char *)dest;
	if (source < dst)
		while (n--)
			dst[n] = source[n];
	else
		while (n--)
			*(dst++) = *(source++);
	return (dest);
}
