/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrizon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:33:24 by tbrizon           #+#    #+#             */
/*   Updated: 2019/04/15 11:33:28 by tbrizon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		DESCRIPTION
**	Inverse le contenu d'une chaîne de charactère.
**	La fonction prend en parametre la chaine de charactere
**	et renvoie cette meme chaine avec le contenu inverse.
*/

char	*ft_strrev(char *str)
{
	int		count;
	int		recount;
	char	tmp;

	count = 0;
	recount = 0;
	while (str[count] != '\0')
		count++;
	count--;
	while (count > recount)
	{
		tmp = str[count];
		str[count] = str[recount];
		str[recount] = tmp;
		recount++;
		count--;
	}
	return (str);
}
