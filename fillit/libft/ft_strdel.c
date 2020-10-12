/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:04:12 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 11:04:14 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**		DESCRIPTION
**	Libere une chaine de charactere avec free(3) et met son pointeur a NULL.
*/

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = 0;
}
