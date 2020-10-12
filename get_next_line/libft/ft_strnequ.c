/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:31:49 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 13:31:50 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Compare lexicographiquement s1 et s2 jusqu’a n caracteres maximum ou
**	bien qu’un ’\0’ ait ete rencontre.
**	Si les deux chaines sont egales, la fonction retourne 1, ou 0 sinon.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n || (!s1 && !s2))
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s1, s2, n) != 0)
		return (0);
	return (1);
}
