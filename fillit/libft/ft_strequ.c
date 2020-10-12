/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:28:28 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 13:28:29 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Compare lexicographiquement s1 et s2. Si les deux chaines sont egales,
**	la fonction retourne 1, ou 0 sinon.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	return (1);
}
