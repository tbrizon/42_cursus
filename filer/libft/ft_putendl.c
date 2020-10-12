/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:59:15 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/05 17:59:16 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Affiche la chaine s sur la sortie standard suivie d'un '\n'.
*/

void	ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}
