/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:26:39 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/08 11:26:41 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Assigne la valeur ’\0’ a tous les caracteres de la chaine.
*/

void	ft_strclr(char *s)
{
	if (!s)
		return ;
	while (*s)
		*s++ = '\0';
}
