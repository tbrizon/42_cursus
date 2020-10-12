/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:51:10 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/03 18:43:45 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it.  The pointer
**	may subsequently be used as an argument to the function free(3).
**	-------------------------------------------------------------------------
**	If insufficient memory is available, NULL is returned and errno is
**	set to ENOMEM.
**	-------------------------------------------------------------------------
**	The strndup() function copies at most n characters from the string s1
**	always NUL terminating the copied string.
*/

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
