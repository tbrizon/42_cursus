/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:54:23 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/09 10:54:24 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.  The pointer may
**	subsequently be used as an argument to the function free(3).
**	-------------------------------------------------------------------------
**	If insufficient memory is available, NULL is returned and errno is set
**	to ENOMEM.
**	-------------------------------------------------------------------------
**	The strndup() function copies at most n characters from the string s1
**	always NUL terminating the copied string.
*/

char	*ft_strndup(const char *str, size_t n)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(dst, str, n);
	dst[n] = '\0';
	return (dst);
}
