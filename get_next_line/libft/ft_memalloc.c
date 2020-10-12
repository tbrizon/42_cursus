/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:05:13 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 10:05:15 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Alloue (avec malloc(3)) et retourne une zone de memoire initialisee a 0.
**	Si l’allocation echoue, la fonction renvoie NULL.
*/

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = (void *)malloc(size);
	if (!(memory = (void *)malloc(size)))
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
