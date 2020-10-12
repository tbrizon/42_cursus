/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:45:21 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 11:46:02 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Cree une nouvelle chaine (avec malloc(3)) resultant des applications
**	successives de f sur chaque caractere de la chaine.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (*s)
		*str++ = f(*s++);
	return (str - len);
}
