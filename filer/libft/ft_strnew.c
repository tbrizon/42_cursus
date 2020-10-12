/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:55:03 by tbrizon           #+#    #+#             */
/*   Updated: 2019/05/03 15:47:43 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une chaine de caractere terminee
**	par un ’\0’. Chaque caractere de la chaine est initialise a ’\0’.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

char	*ft_strnew(size_t size)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res = ft_memset(res, '\0', size + 1);
	return (res);
}
