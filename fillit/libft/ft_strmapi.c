/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:16:54 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 12:16:55 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Cree une nouvelle chaine (avec malloc(3)) resultant des applications
**	successives de f sur chaque caractere de la chaine en precisant son
**	index.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		len;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (*s)
		*str++ = f(i++, *s++);
	return (str - len);
}
