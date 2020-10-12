/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 10:17:02 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 10:17:02 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**		DESCRIPTION
**	Libere la zone d'un pointeur avec free(3), puis le met a NULL.
*/

void	ft_memdel(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = NULL;
}
