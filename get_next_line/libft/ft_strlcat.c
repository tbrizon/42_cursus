/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:51:12 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/03 18:51:14 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	The strlcpy() and strlcat() functions copy and concatenate strings
**	respectively.  They are designed to be safer, more consistent, and less
**	error prone replacements for strncpy(3) and strncat(3).  Unlike those
**	functions, strlcpy() and strlcat() take the full size of the buffer (not
**	just the length) and guarantee to NUL-terminate the result (as long as
**	size is larger than 0 or, in the case of strlcat(), as long as there is
**	at least one byte free in dst).  Note that a byte for the NUL should be
**	included in size.  Also note that strlcpy() and strlcat() only operate on
**	true ``C'' strings.  This means that for strlcpy() src must be NUL-termi-
**	nated and for strlcat() both src and dst must be NUL-terminated.
**	-------------------------------------------------------------------------
**	The strlcpy() function copies up to size - 1 characters from the NUL-ter-
**	minated string src to dst, NUL-terminating the result.
**	-------------------------------------------------------------------------
**	The strlcat() function appends the NUL-terminated string src to the end
**	of dst.  It will append at most size - strl'en(dst) - 1 bytes, NUL-termi-
**	nating the result.
**	-------------------------------------------------------------------------
**	The source and destination strings should not overlap, as the behavior is
**	undefined.
**	-------------------------------------------------------------------------
**		RETURN VALUES
**	The strlcpy() and strlcat() functions return the total length of the
**	string they tried to create.  For strlcpy() that means the length of src.
**	For strlcat() that means the initial length of dst plus the length of
**	src.  While this may seem somewhat confusing, it was done to make trunca-
**	tion detection simple.
**	-------------------------------------------------------------------------
**	Note however, that if strlcat() traverses size characters without finding
**	a NUL, the length of the string is considered to be size and the destina-
**	tion string will not be NUL-terminated (since there was no space for the
**	NUL).  This keeps strlcat() from running off the end of a string.  In
**	practice this should not happen (as it means that either size is incor-
**	rect or that dst is not a proper ``C'' string).  The check exists to pre-
**	vent potential security problems in incorrect code.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size < dst_len)
		return (src_len + size);
	while (src[i] != '\0' && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
